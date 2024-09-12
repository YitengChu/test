#include "lz4.h"
#include "compress.h"
#include "uncompress.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<fstream>
#include<unordered_map>
#include<map>
#include<string>
#include <queue>
#include<algorithm>
#include<set>
using namespace std;
int main() {
	string input = "C:\\Users\\Lenovo\\Desktop\\dddd.txt";
	unordered_map<string, int>map1;
	map<string, int>  doc;
	doc = lz4_compress(input, 4000, 1000, 1000, 15);
	string output = compress(doc, input, 12, 4);
	string compressfile = "C:\\Users\\Lenovo\\Desktop\\dddd.txt.rp";
	string output2 = uncompress(compressfile, 12, 4);
}