### 解题思路
执行用时 :16 ms, 在所有 C++ 提交中击败了90.63% 的用户
内存消耗 :11.6 MB, 在所有 C++ 提交中击败了20.68%的用户

### 代码

```cpp
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
    	std::map<string, int> words_info;
    	for(size_t i=0;i<words.size();++i){
    		words_info[words[i]]++;
    	}
    	vector<pair<string, int>> vec_sorted_words(words_info.begin(),words_info.end());
    	std::sort(vec_sorted_words.begin(), vec_sorted_words.end(), [](const pair<string,int>& l, const pair<string,int>& r){
    		if(l.second == r.second){
        		for(size_t i=0;i<min(l.first.size(), r.first.size());++i){
                    if(l.first[i] == r.first[i]) continue;
        			return l.first[i] < r.first[i];
        		}
    		}
    		return l.second > r.second;
    	});
    	vector<string> words_sorted;
    	for(int i=0;i<k;++i){
    		words_sorted.push_back(vec_sorted_words[i].first);
    	}
    	return words_sorted;
    }
};
```