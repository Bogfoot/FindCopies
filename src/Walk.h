/*
Program za pretraživanje datoteka i spremanje fileova s određenom ekstenzijom
Treba compileati s " -lstdc++fs", također je ok compileati sa -std=c++17
*/
#include <algorithm>
#include <chrono>
#include <filesystem>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

namespace fs = std::filesystem;
using namespace std::chrono_literals;
using svec = std::vector<std::string>;

static bool is_finished = false;

// Funkcija za dobivanje liste fileova
void FindCopies(const std::string inPath, svec &inFiles,
                const std::string outPath, svec &outFiles, svec &Copies);
void findCopies(svec &Source, svec &Target, svec &Copies);
void getFiles(const std::string path, svec &files);
bool isExe(fs::perms path);
void spin();
