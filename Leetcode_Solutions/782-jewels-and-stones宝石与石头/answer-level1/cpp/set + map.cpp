### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numJewelsInStones(string J, string S) {
    	int num_jewels = 0;

    	map<char, int> record;
    	set<char> s_self_stone;
    	for(size_t i=0;i<S.size();++i){
    		record[S[i]]++;
    		s_self_stone.insert(S[i]);
    	}
    	for(size_t i=0;i<s_self_stone.size();++i){
    		auto index = s_self_stone.begin();
    		std::advance(index, i);
    		auto ind = std::find(J.begin(), J.end(), *index);
    		if(ind != J.end()){
    			num_jewels += record[*index];
    		}
    	}
    	return num_jewels;
    }
};
```