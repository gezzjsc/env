//
// Created by zhengzheng.ge on 2019-03-04.
//

#include "env_posix.h"
#include <string>
#include <vector>
#include <iostream>

int main() {
//  std::cout << EnvPosix::CreateDir("test_dir");
//  std::cout << EnvPosix::DeleteDir("test_dir");
//  std::cout << EnvPosix::FileExists("test_dir");
//  std::vector<std::string> sub_files;
//  std::vector<std::string> sub_dirs;
//  EnvPosix::GetChildren("test_dir", &sub_files, &sub_dirs);
  std::string file_name = "/home/root/a.txt", dir_name, base_name;
  if (EnvPosix::DirName(file_name, &dir_name)) {
    std::cout << dir_name << std::endl;
  }
  if (EnvPosix::BaseName(file_name, &base_name)) {
    std::cout << base_name << std::endl;
  }

//  EnvPosix::DeleteFile("test_dir/.kk.txt");
//  EnvPosix::RenameFile("test_dir/a.txt", "test_dir/aa.txt");
  return 0;
}
