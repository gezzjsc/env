//
// Created by zhengzheng.ge on 2019-03-01.
//

#ifndef ENV_INCLUDE_ENV_H
#define ENV_INCLUDE_ENV_H

#include <string>
#include <vector>

class Env {
 public:
  Env() = default;

  Env(const Env&) = delete;
  Env& operator=(const Env&) = delete;

  virtual ~Env() {}

  // Returns true iff the named file exists.
  virtual bool FileExists(const std::string& file_name) = 0;

  // Store in *result the names of the children of the specified directory.
  // The names are relative to "dir".
  // Original contents of *results are dropped.
  virtual bool GetChildren(const std::string& dir,
                             std::vector<std::string>* sub_reg_files,
                             std::vector<std::string>* sub_dirs) = 0;

  // Delete the named file.
  virtual bool DeleteFile(const std::string& file_name) = 0;

  // Create the specified directory.
  virtual bool CreateDir(const std::string& dir_name) = 0;

  // Delete the specified directory.
  virtual bool DeleteDir(const std::string& dir_name) = 0;

  // Store the size of file_name in *file_size.
  virtual bool GetFileSize(const std::string& file_name,
                           uint64_t* file_size) = 0;

  // Rename file src to target.
  virtual bool RenameFile(const std::string& src,
                          const std::string& target) = 0;
};

#endif // ENV_INCLUDE_ENV_H
