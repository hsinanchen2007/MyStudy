统计每个string中a-b每个字母的次数，异位词的次数会相等，把次数分布当做一个哈希的输入即可
```
//方法1，结合unordered_multimap
size_t hashFunc(const string& str) {
	size_t table[26] = { 0 };
	for (auto c : str)++table[c - 'a'];
	size_t res = 0;
	for (auto t : table) {
		(res *= 33) += t;//随便选的一个质数，size_t超过2^31-1的时候会自动从0开始
	}
	return res;
}
//方法2，结合unordered_multiset
struct hashObj {
	size_t operator()(const string& str)const {
		size_t table[26] = { 0 };
		for (auto c : str)++table[c - 'a'];
		size_t res = 0;
		for (auto t : table) {
			(res *= 33) += t;
		}
		return res;
	}
};
struct equalObj {
	bool operator()(const string&s1, const string&s2)const {
		size_t table1[26] = { 0 }, table2[26] = { 0 };
		for (auto c : s1)++table1[c - 'a'];
		for (auto c : s2)++table2[c - 'a'];
		for (int i = 0;i < 26;++i) {
			if (table1[i] != table2[i])return false;
		}
		return true;
	}
};
class Solution {

public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		//方法1，存在冲突的可能，这道题里能过
		// unordered_multimap<size_t, string> m;
		// vector<vector<string>>res;
		// for (auto& s : strs)m.insert({hashFunc(s),s});
		// auto it = m.begin();
		// while (it != m.end()) {
		// 	vector<string>cur{move(it->second)};
		// 	auto cmp = it;
		// 	while (++cmp!=m.end() && cmp->first == it->first) {
		// 		cur.emplace_back(move(cmp->second));
		// 	}
		// 	it = cmp;
		// 	res.emplace_back(move(cur));
		// }
		// return res;

		//方法二，重写hashFunc和equal，避免冲突
		unordered_multiset<string, hashObj, equalObj> m;
		vector<vector<string>>res;
		for (auto& s : strs)m.insert(s);
		auto it = m.begin();
		while (it != m.end()) {
			auto range = m.equal_range(*it);
			vector<string> cur;
			for (auto r = range.first;r != range.second;++r)
				cur.emplace_back(move(*r));
			it = range.second;
			res.emplace_back(move(cur));
		}
		return res;
    }
};
```
