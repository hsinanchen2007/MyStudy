### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
struct cmp {
	bool operator()(string a, string b) {
		if (a.size() == b.size()) {
			for (int i = 0;i < a.size();i++) {
				if (a[i] == b[i])continue;
				else return a[i] < b[i];
			}
			return false;
		}
		else return  a.size() > b.size();
	}
};
bool check_string(unordered_map<char, vector<string>> map,string temp,bool first_check) {
	if (temp.size() == 0)return true;
	for (int i = 0;i < map[temp.front()].size();i++) {
		int cur_size = map[temp.front()][i].size();
		if ((first_check&&cur_size == temp.size()) || cur_size > temp.size())continue;
		string sub_temp(temp.begin(), temp.begin() + cur_size);
		if (map[temp.front()][i] == sub_temp) {
			string next_temp(temp.begin() + cur_size, temp.end());
			if (check_string(map, next_temp,false))return true;
		}
	}
	return false;
}
string longestWord(vector<string>& words) {
	sort(words.begin(), words.end(),cmp());
	unordered_map<char, vector<string>> map;
	for (int i = 0;i < words.size();i++) {
		map[words[i].front()].push_back(words[i]);
	}
	for (int i = 0;i < words.size();i++) {
		string temp = words[i];
		if (check_string(map, temp,true))return words[i];
	}
	return "" ;
}

};
```