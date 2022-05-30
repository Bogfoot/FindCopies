/*
Program za pretraživanje datoteka i spremanje fileova s određenom ekstenzijom
Treba compileati s " -lstdc++fs", također je ok compileati sa -std=c++17
*/
// Moji includeovi
#include "Walk.h"

svec FindCopies(const std::string inPath, svec &inFiles,
                const std::string outPath, svec &outFiles) {
  svec Copies;
  if (!fs::is_directory((fs::path)inPath) ||
      !fs::is_directory((fs::path)outPath)) {
    std::cout << "Either [Target] or [Source] is not a path to a directory."
              << std::endl;
    return Copies;
  }
  getFiles(inPath, inFiles);
  getFiles(outPath, outFiles);
  findCopies(inFiles, outFiles, Copies);
  if (Copies.size() == 0)
    std::cout << "No copies were found." << std::endl;
  return Copies;
}

void findCopies(svec &Source, svec &Target, svec &Copies) {
  for (const auto &SFile : Source) {
    for (const auto &TFile : Target) {
      if (fs::absolute((fs::path)SFile) == fs::absolute((fs::path)TFile))
        continue;
      else if ((fs::path(SFile).filename() == fs::path(TFile).filename()))
        Copies.push_back(SFile);
    }
  }
  std::sort(Copies.begin(), Copies.end());
  Copies.erase(unique(Copies.begin(), Copies.end()), Copies.end());
}

void getFiles(const std::string path, svec &files) {
  for (const auto &entry : fs::recursive_directory_iterator(path)) {
    if (fs::is_regular_file((fs::path)entry) ||
        !isExe(fs::status(entry).permissions())) {
      files.push_back(entry.path());
      std::cout << entry << std::endl;
    }
  }
}

bool isExe(fs::perms p) {
  if ((p & fs::perms::owner_exec) != fs::perms::none)
    return true;
  else
    return false;
}
