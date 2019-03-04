//
// Created by zhengzheng.ge on 2019-03-01.
//

#ifndef ENV_INCLUDE_ENV_POSIX_H
#define ENV_INCLUDE_ENV_POSIX_H

#include <string>
#include <vector>
#include "env.h"

class EnvPosix : public Env {
 public:
  EnvPosix();

  EnvPosix(const EnvPosix&) = delete;
  EnvPosix& operator=(const EnvPosix&) = delete;

  virtual ~EnvPosix();

  // Returns true iff the named file exists.
  virtual bool FileExists(const std::string& file_name);

  // Store in *result the names of the children of the specified directory.
  // The names are relative to "dir".
  // Original contents of *results are dropped.
  virtual bool GetChildren(const std::string& dir,
                           std::vector<std::string>* sub_reg_files,
                           std::vector<std::string>* sub_dirs);

  // Delete the named file.
  virtual bool DeleteFile(const std::string& file_name);

  // Create the specified directory.
  virtual bool CreateDir(const std::string& dir_name);

  // Delete the specified directory.
  virtual bool DeleteDir(const std::string& dir_name);

  // Store the size of file_name in *file_size.
  virtual bool GetFileSize(const std::string& file_name,
                           uint64_t* file_size);

  // Rename file src to target.
  virtual bool RenameFile(const std::string& src,
                          const std::string& target);
};

#endif // ENV_INCLUDE_ENV_POSIX_H
