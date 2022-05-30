/*
Program za pretraživanje datoteka i spremanje fileova s određenom ekstenzijom
Treba compileati s " -lstdc++fs", također je ok compileati sa -std=c++17
*/
#include <algorithm>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

namespace fs = std::filesystem;
using svec = std::vector<std::string>;

// Funkcija za dobivanje liste fileova
bool isExe(fs::perms path);
void getFiles(const std::string path, svec &files);
svec FindCopies(const std::string inPath, svec &inFiles,
                const std::string outPath, svec &outFiles);
void findCopies(svec &Source, svec &Target, svec &Copies);
