//
// Created by zhengzheng.ge on 2019-03-04.
//

#include <env_posix.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string>
#include <vector>

EnvPosix::EnvPosix() {}

EnvPosix::~EnvPosix() {}

bool EnvPosix::FileExists(const std::string& file_name) {
  return access(file_name.c_str(), F_OK) == 0;
}

bool EnvPosix::GetChildren(const std::string& dir,
                           std::vector<std::string>* sub_reg_files,
                           std::vector<std::string>* sub_dirs) {
  sub_reg_files->clear();
  sub_dirs->clear();
  DIR* d = opendir(dir.c_str());
  if (d == nullptr) {
    return false;
  }
  struct dirent* entry;
  while ((entry = readdir(d)) != nullptr) {
    if ((strcmp(entry->d_name, ".") == 0) ||
        (strcmp(entry->d_name, "..") == 0)) {
      continue;
    }
    if (entry->d_type == DT_REG) {
      sub_reg_files->push_back(entry->d_name);
    } else if (entry->d_type == DT_DIR) {
      sub_dirs->push_back(entry->d_name);
    }
  }
  closedir(d);
  return true;
}

bool EnvPosix::DeleteFile(const std::string& file_name) {
  return unlink(file_name.c_str()) == 0;
}

bool EnvPosix::CreateDir(const std::string& dir_name) {
  return mkdir(dir_name.c_str(), 0755) == 0;
}

bool EnvPosix::DeleteDir(const std::string& dir_name) {
  return rmdir(dir_name.c_str()) == 0;
}

bool EnvPosix::GetFileSize(const std::string& file_name, uint64_t* size) {
  struct stat sbuf;
  if (stat(file_name.c_str(), &sbuf) != 0) {
    *size = 0;
    return false;
  } else {
    *size = sbuf.st_size;
    return true;
  }
}

bool EnvPosix::RenameFile(const std::string& src, const std::string& target) {
  return rename(src.c_str(), target.c_str()) == 0;
}
