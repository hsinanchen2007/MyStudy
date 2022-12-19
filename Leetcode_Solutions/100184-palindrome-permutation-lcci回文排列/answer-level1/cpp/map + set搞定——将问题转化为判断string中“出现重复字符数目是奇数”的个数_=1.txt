### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :8.5 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
    	map<char,pair<int, int>> record;
    	set<char> no_dup_s;
    	for(size_t i=0;i<s.size();++i){
    		record[s[i]].first++;
    		record[s[i]].second = (record[s[i]].first % 2);
    		no_dup_s.insert(s[i]);
    	}
    	int odd_num = 0; // string s中重复字符出现的数目是奇数
    	for(size_t i=0;i<no_dup_s.size();++i){
    		auto ind = no_dup_s.begin();
    		std::advance(ind, i);
    		char ch = *ind;
//    		cout << ch << " ";
    		record[ch].second ? odd_num++ : 0;
    	}
    	return odd_num <= 1;
    }
};
```