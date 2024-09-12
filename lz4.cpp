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

std::vector<std::string> removeSubstrings(std::vector<std::string> strings, std::unordered_map<std::string, int>  preorder2) {
	std::set<int>out;
	std::string node;
	int nodeint;
	for (int i = 0; i < strings.size() - 1; i++) {
		if (i == 0) {
			if (strings[i].substr(0, 4) == strings[i + 1].substr(0, 4)) {
				if (strings[i].size() <= strings[i + 1].size()) {
					if (strings[i] == strings[i + 1].substr(0, strings[i].size())) {
						out.insert(i);
						node = strings[i + 1];
						nodeint = i + 1;
					}
					else {

						int matchtempremove = 0;
						int len = std::min(strings[i].length(), strings[i + 1].length());
						for (int j = 0; j < len; ++j) {
							if (strings[i][j] != strings[i + 1][j]) {
								break;
							}
							matchtempremove++;
						}
						int maxtemp1 = 0, maxtemp2 = 0;
						for (int j = matchtempremove; j < strings[i].size(); j++) {
							if (preorder2[strings[i].substr(j - 3, 4)] > maxtemp1) { maxtemp1 = preorder2[strings[i].substr(j - 3, 4)]; }
						}
						for (int j = matchtempremove; j < strings[i + 1].size(); j++) {
							if (preorder2[strings[i + 1].substr(j - 3, 4)] > maxtemp2) { maxtemp2 = preorder2[strings[i + 1].substr(j - 3, 4)]; }
						}
						if (maxtemp1 <= maxtemp2) { node = strings[i + 1]; out.insert(i); nodeint = i + 1; }
						else { node = strings[i]; out.insert(i + 1); nodeint = i; }

					}

				}
				else {
					int matchtempremove = 0;
					int len = std::min(strings[i].length(), strings[i + 1].length());
					for (int j = 0; j < len; ++j) {
						if (strings[i][j] != strings[i + 1][j]) {
							break;
						}
						matchtempremove++;
					}
					int maxtemp1 = 0, maxtemp2 = 0;
					for (int j = matchtempremove; j < strings[i].size(); j++) {
						if (preorder2[strings[i].substr(j - 3, 4)] > maxtemp1) { maxtemp1 = preorder2[strings[i].substr(j - 3, 4)]; }
					}
					for (int j = matchtempremove; j < strings[i + 1].size(); j++) {
						if (preorder2[strings[i + 1].substr(j - 3, 4)] > maxtemp2) { maxtemp2 = preorder2[strings[i + 1].substr(j - 3, 4)]; }
					}
					if (maxtemp1 <= maxtemp2) { node = strings[i + 1]; out.insert(i); nodeint = i + 1; }
					else { node = strings[i]; out.insert(i + 1); nodeint = i; }
				}
			}
			else { node = strings[i + 1]; nodeint = i + 1; }

		}
		else {
			if (strings[i].substr(0, 4) == strings[i + 1].substr(0, 4)) {
				if (strings[i].size() <= strings[i + 1].size()) {
					if (strings[i] == strings[i + 1].substr(0, strings[i].size())) {
						if (out.count(i) > 0) {

							int matchtempremove = 0;
							int len = std::min(node.length(), strings[i + 1].length());
							for (int j = 0; j < len; ++j) {
								if (node[j] != strings[i + 1][j]) {
									break;
								}
								matchtempremove++;
							}
							int maxtemp1 = 0, maxtemp2 = 0;
							for (int j = matchtempremove; j < node.size(); j++) {
								if (preorder2[node.substr(j - 3, 4)] > maxtemp1) { maxtemp1 = preorder2[node.substr(j - 3, 4)]; }
							}
							for (int j = matchtempremove; j < strings[i + 1].size(); j++) {
								if (preorder2[strings[i + 1].substr(j - 3, 4)] > maxtemp2) { maxtemp2 = preorder2[strings[i + 1].substr(j - 3, 4)]; }
							}
							if (maxtemp1 <= maxtemp2) { node = strings[i + 1]; out.insert(nodeint); }
							else { out.insert(i + 1); }

						}
						else {
							out.insert(i);
							node = strings[i + 1];
							nodeint = i + 1;
						}
					}
					else {

						int matchtempremove = 0;
						int len = std::min(node.length(), strings[i + 1].length());
						for (int j = 0; j < len; ++j) {
							if (node[j] != strings[i + 1][j]) {
								break;
							}
							matchtempremove++;
						}
						int maxtemp1 = 0, maxtemp2 = 0;
						for (int j = matchtempremove; j < node.size(); j++) {
							if (preorder2[node.substr(j - 3, 4)] > maxtemp1) { maxtemp1 = preorder2[node.substr(j - 3, 4)]; }
						}
						for (int j = matchtempremove; j < strings[i + 1].size(); j++) {
							if (preorder2[strings[i + 1].substr(j - 3, 4)] > maxtemp2) { maxtemp2 = preorder2[strings[i + 1].substr(j - 3, 4)]; }
						}
						if (maxtemp1 <= maxtemp2) { node = strings[i + 1]; out.insert(nodeint); }
						else { out.insert(i + 1); }

					}
				}
				else {
					int matchtempremove = 0;
					int len = std::min(node.length(), strings[i + 1].length());
					for (int j = 0; j < len; ++j) {
						if (node[j] != strings[i + 1][j]) {
							break;
						}
						matchtempremove++;
					}
					int maxtemp1 = 0, maxtemp2 = 0;
					for (int j = matchtempremove; j < node.size(); j++) {
						if (preorder2[node.substr(j - 3, 4)] > maxtemp1) { maxtemp1 = preorder2[node.substr(j - 3, 4)]; }
					}
					for (int j = matchtempremove; j < strings[i + 1].size(); j++) {
						if (preorder2[strings[i + 1].substr(j - 3, 4)] > maxtemp2) { maxtemp2 = preorder2[strings[i + 1].substr(j - 3, 4)]; }
					}
					if (maxtemp1 <= maxtemp2) { node = strings[i + 1]; out.insert(nodeint); }
					else { out.insert(i + 1); }
				}
			}
			else {
				node = strings[i + 1]; nodeint = i + 1;
			}

		}
	}
	std::vector<std::string>result;
	for (int i = 0; i < strings.size(); i++) {
		if (out.count(i) > 0) {}
		else { result.push_back(strings[i]); }
	}
	return result;
}








struct MyStruct {
	std::string a;
	int b;
};
struct Compare {
	bool operator()(const MyStruct& x, const MyStruct& y) {
		return x.b > y.b; // 按照 b 的值进行比较
	}
};
bool cmp_value(const std::pair<std::string, int>& left, const std::pair<std::string, int>& right) {
	return left.second < right.second;
}

//std::unordered_map<std::string, int>  lz4_compress(string str, int inputlen, int spacesavingk) {
std::map<std::string, int>  lz4_compress(std::string str, int inputlen, int spacesavingk, int k, int offset) {
	std::unordered_map<std::string, int> hash_table;
	std::vector<char>hash_table2;
	int delete_number = 0;
	std::unordered_map<std::string, int>map1;
	std::priority_queue<MyStruct, std::vector<MyStruct>, Compare> minHeap;

	std::unordered_map<std::string, int>  preorder1;
	std::unordered_map<std::string, int>  preorder2;
	int preordernumber = 0;


	std::string bufferstr = "";
	char  ch1, ch2, ch3;
	int spacesavingcount = 0;
	int i = 0; int bufferlen = 0;
	std::ifstream inputFile(str);
	if (inputFile.is_open()) {
		char c;
		while (inputFile.get(c)) {
			//	cout << 1 << endl;
			if (i == 0) { ch1 = c; }
			else if (i == 1) { ch2 = c; }
			else if (i == 2) { ch3 = c; }
			else if (i == 3) {
				bufferstr += ch1; bufferstr += ch2; bufferstr += ch3; bufferstr += c;
				hash_table[bufferstr] = i - 3;
				bufferlen = 4;

				hash_table2.push_back(c);

			}
			else if (i == 4) { ch1 = c; }
			else if (i == 5) { ch2 = c; }
			else if (i == 6) { ch3 = c; }
			else {
				std::string buffertemp = "";
				buffertemp += ch1; buffertemp += ch2; buffertemp += ch3; buffertemp += c;
				auto it = hash_table.find(buffertemp);
				if (it != hash_table.end()) {
					int current_match_length = 4;
					std::string match_str = "";

					auto orderjudge = preorder1.find(buffertemp);
					if (orderjudge != preorder1.end()) {
						preorder2[buffertemp]++;
					}
					else {
						preorder1[buffertemp] = preordernumber;
						preordernumber++;
						preorder2[buffertemp] = 2;
					}


					match_str = buffertemp;
					i++;
					ch1 = ch2; ch2 = ch3; ch3 = c;
					bool judgeend = false;
					if (inputFile.get(c)) {
						//inputFile.seekg(-1, std::ios_base::cur);
						inputFile.unget();
					}
					else { judgeend = true; }
					int itsecond = it->second + 1;
					while (inputFile.get(c)) {
						std::string buffertemp2 = "";
						buffertemp2 += ch1; buffertemp2 += ch2; buffertemp2 += ch3; buffertemp2 += c;
						if ((itsecond + delete_number) < hash_table2.size() && c == hash_table2[itsecond + delete_number] && current_match_length < offset) {

							auto orderjudge2 = preorder1.find(buffertemp2);
							if (orderjudge2 != preorder1.end()) {
								preorder2[buffertemp2]++;
							}
							else {
								preorder1[buffertemp2] = preordernumber;
								preordernumber++;
								preorder2[buffertemp2] = 2;
							}

							match_str += c;
							current_match_length++;
							ch1 = ch2; ch2 = ch3; ch3 = c;
							i++;
							judgeend = true;
							itsecond++;
						}
						else {
							judgeend = false;
							//space-savign算法处理

							if (map1.count(match_str)) {
								map1[match_str]++;
							}
							else {
								if (spacesavingcount < spacesavingk) {
									map1[match_str] = 2;
									spacesavingcount++;
									MyStruct s1 = { match_str, 2 };
									minHeap.push(s1);
								}
								else {
									MyStruct minElement = minHeap.top();
									while (minElement.b != map1[minElement.a]) {
										MyStruct s1 = { minElement.a, map1[minElement.a] };
										minHeap.pop();
										minHeap.push(s1);
										minElement = minHeap.top();
									}
									map1.erase(minElement.a);
									map1[match_str] = 1 + minElement.b;
									minHeap.pop();
									MyStruct s1 = { match_str, 2 };
									minHeap.push(s1);
								}
							}
							for (int z = 0; z < current_match_length; z++) {
								if (bufferlen < inputlen) {
									bufferlen++;
									hash_table[bufferstr.substr(bufferstr.length() - 3, 3) + match_str[z]] = i - 7 - (current_match_length - 4 - z);

									hash_table2.push_back(match_str[z]);

									bufferstr += match_str[z];
								}
								else {
									hash_table.erase(bufferstr.substr(0, 4));
									hash_table[bufferstr.substr(bufferstr.length() - 3, 3) + match_str[z]] = i - 7 - (current_match_length - 4 - z);

									delete_number++;
									hash_table2.push_back(match_str[z]);

									bufferstr += match_str[z];
									bufferstr = bufferstr.substr(1);
								}

							}
							ch1 = c;
							i++;
							if (inputFile.get(c)) {
								ch2 = c;
								i++;
							}
							else { break; }
							if (inputFile.get(c))
							{
								ch3 = c;
								//		cout << match_str<<endl;
							}
							else { break; }
							break;
						}
					}


					if (judgeend) {
						judgeend = false;
						//space-savign算法处理

						if (map1.count(match_str)) {
							map1[match_str]++;
						}
						else {
							if (spacesavingcount < spacesavingk) {
								map1[match_str] = 2;
								spacesavingcount++;
								MyStruct s1 = { match_str, 2 };
								minHeap.push(s1);
							}
							else {
								MyStruct minElement = minHeap.top();
								while (minElement.b != map1[minElement.a]) {
									MyStruct s1 = { minElement.a, map1[minElement.a] };
									minHeap.pop();
									minHeap.push(s1);
									//	minElement.b = map1[minElement.a];
										// 重新排序堆
										//std::make_heap(minHeap.begin(), minHeap.end(), Compare());  // 重新调整堆的顺序
									//	std::make_heap(const_cast<MyStruct*>(&minHeap.top()), const_cast<MyStruct*>(&minHeap.top()) + minHeap.size(), minHeap);
									minElement = minHeap.top();
								}
								map1.erase(minElement.a);
								map1[match_str] = 1 + minElement.b;
								minHeap.pop();
								MyStruct s1 = { match_str, 2 };
								minHeap.push(s1);
							}
						}
						for (int z = 0; z < current_match_length; z++) {
							if (bufferlen < inputlen) {
								bufferlen++;
								hash_table[bufferstr.substr(bufferstr.length() - 3, 3) + match_str[z]] = i - 7 - (current_match_length - 4 - z);

								hash_table2.push_back(match_str[z]);

								bufferstr += match_str[z];
							}
							else {
								hash_table.erase(bufferstr.substr(0, 4));
								hash_table[bufferstr.substr(bufferstr.length() - 3, 3) + match_str[z]] = i - 7 - (current_match_length - 4 - z);

								delete_number++;
								hash_table2.push_back(match_str[z]);

								bufferstr += match_str[z];
								bufferstr = bufferstr.substr(1);
							}

						}
						ch1 = c;
						i++;
						if (inputFile.get(c)) {
							ch2 = c;
							i++;
						}
						if (inputFile.get(c))
						{
							ch3 = c;
							//		cout << match_str<<endl;
						}
					}


				}
				else {
					if (bufferlen < inputlen) {
						bufferlen++;
						hash_table[bufferstr.substr(bufferstr.length() - 3, 3) + ch1] = i - 6;

						hash_table2.push_back(ch1);

						bufferstr += ch1;
						ch1 = ch2; ch2 = ch3; ch3 = c;
					}
					else {
						hash_table.erase(bufferstr.substr(0, 4));
						hash_table[bufferstr.substr(bufferstr.length() - 3, 3) + ch1] = i - 6;

						delete_number++;
						hash_table2.push_back(ch1);

						bufferstr += ch1;
						bufferstr = bufferstr.substr(1);
						ch1 = ch2; ch2 = ch3; ch3 = c;

					}
				}
			}
			i++;
		}
		inputFile.close();
	}
	else {
		std::cout << "Failed to open the file." << std::endl;
	}


	// 使用auto关键字定义迭代器
	for (auto it = map1.begin(); it != map1.end(); ++it) {
		std::cout << "Key: " << it->first << "     " << it->first.size() << ", Value: " << it->second << std::endl;
	}

	std::vector<std::string> topKeys;
	//vector<vector<char>>  doc;
	for (int i = 0; i < k; ++i) {
		auto it = std::max_element(map1.begin(), map1.end(), cmp_value);
		if (it != map1.end()) {
			topKeys.push_back(it->first);
			map1.erase(it);
		}
	}
	std::map<std::string, int>docz;
	int count = 0;

	std::sort(topKeys.begin(), topKeys.end());
	std::vector<std::string> topKeystemp = removeSubstrings(topKeys, preorder2);
	topKeys = topKeystemp;

	for (const std::string& key : topKeys) {
		docz[key] = count;
		/*	for (int j = 0; j < key.length() - 3; j++) {
				vector<char> docnum;
				docnum.push_back(key[j]);
				docnum.push_back(key[j + 1]);
				docnum.push_back(key[j + 2]);
				docnum.push_back(key[j + 3]);
				doc.push_back(docnum);
				count++;
			}*/
	}
	return docz;
}