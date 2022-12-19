### 解题思路
执行用时 :32 ms, 在所有 C++ 提交中击败了88.14% 的用户
内存消耗 :12.3 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    	for(auto& iter_row:matrix){
			auto ind = std::find(iter_row.begin(), iter_row.end(), target);
			if(ind != iter_row.end()) return true;
    	}
    	return false;
    }
};
```