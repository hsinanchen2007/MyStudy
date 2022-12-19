### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string frequencySort(string s) {
    	std::map<char, int> s_info;
    	string s_sorted;
    	for(size_t i=0;i<s.size();++i){
    		s_info[s[i]]++;
    	}
    	vector<pair<char, int>> vec_s_sorted(s_info.begin(), s_info.end());
    	std::sort(vec_s_sorted.begin(),vec_s_sorted.end(),[](const pair<char,int>& l, const pair<char,int>& r){
    		return l.second > r.second;
    	});
    	for(auto& iter:vec_s_sorted){
    		for(int i=0;i<iter.second;++i){
    			s_sorted += iter.first;
    		}
    	}
    	return s_sorted;
    }
};
```