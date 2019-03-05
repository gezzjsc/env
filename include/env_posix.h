//
// Created by zhengzheng.ge on 2019-03-01.
//

#ifndef ENV_INCLUDE_ENV_POSIX_H
#define ENV_INCLUDE_ENV_POSIX_H

#include <string>
#include <vector>

class EnvPosix {
 public:
  EnvPosix();

  EnvPosix(const EnvPosix&) = delete;
  EnvPosix& operator=(const EnvPosix&) = delete;

  virtual ~EnvPosix();

  // Returns true iff the named file exists.
  static bool FileExists(const std::string& file_name);

  // Store in *result the names of the children of the specified directory.
  // The names are relative to "dir".
  // Original contents of *results are dropped.
  static bool GetChildren(const std::string& dir,
                           std::vector<std::string>* sub_reg_files = nullptr,
                           std::vector<std::string>* sub_dirs = nullptr);

  // Delete the named file.
  static bool DeleteFile(const std::string& file_name);

  // Create the specified directory.
  static bool CreateDir(const std::string& dir_name);

  // Delete the specified directory.
  static bool DeleteDir(const std::string& dir_name);

  // Store the size of file_name in *file_size.
  static bool GetFileSize(const std::string& file_name,
                           uint64_t* file_size);

  // Rename file src to target.
  static bool RenameFile(const std::string& src,
                          const std::string& target);

  // Returns the directory name in a path pointing to a file.
  static bool DirName(const std::string& file_name,
                      std::string* dir_name);

  // Extracts the file name from a path pointing to a file.
  static bool BaseName(const std::string &file_name,
                       std::string *base_name);
};

#endif // ENV_INCLUDE_ENV_POSIX_H
