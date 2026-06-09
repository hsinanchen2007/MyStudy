### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了68.95% 的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了5.17%的用户

### 代码

```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
    	multiset<int, greater<int>> ordered_stones;
    	for(auto& iter:stones){
    		ordered_stones.insert(iter);
    	}
    	while(ordered_stones.size()){
    		if(ordered_stones.size() == 1) return *ordered_stones.begin();
    		auto iter = ordered_stones.begin();
    		auto iter1 = ordered_stones.begin();
    		std::advance(iter1, 1);
    		int diff = *iter - *iter1;
			ordered_stones.erase(iter1);
			ordered_stones.erase(iter);
			if(diff){
				ordered_stones.insert(diff);
			}
    	}
    	return 0;
    }
};
```