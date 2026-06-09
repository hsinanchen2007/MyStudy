### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了59.28% 的用户
内存消耗 :8.1 MB, 在所有 C++ 提交中击败了66.71%的用户

### 代码

```cpp
class Solution {
public:
    int getSum(int a, int b) {
    	vector<int> vec = {a,b};
    	return std::accumulate(vec.begin(), vec.end(), 0);
    }
};
```