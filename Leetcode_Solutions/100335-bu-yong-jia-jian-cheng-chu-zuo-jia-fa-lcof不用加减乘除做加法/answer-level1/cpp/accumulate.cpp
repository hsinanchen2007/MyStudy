### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :8.3 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    int add(int a, int b) {
    	vector<int> v = {a,b};
    	return std::accumulate(v.begin(), v.end(), 0);
    }
};
```