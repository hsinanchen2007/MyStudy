```
class Solution {
public:	
	vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
		set<string> mySet(products.begin(), products.end());
		// 定义一个不断收敛的区间
		auto first = mySet.begin();
		auto second = mySet.end();
		vector<vector<string>> ret;
		for (int i = 1; i <= searchWord.size(); i++) {
			string sub = searchWord.substr(0, i); // 当前要匹配的字符串
			first = mySet.lower_bound(sub); // 找到第一个匹配元素，压缩区间
			sub[sub.size() - 1]++; 
			second = mySet.lower_bound(sub); // 找到最后一个匹配元素，压缩区间
			vector<string> current(first, second);
			ret.emplace_back(current.size() > 3 ? vector<string>(current.begin(), current.begin() + 3) : current);
		}
		return ret;
	}
};
