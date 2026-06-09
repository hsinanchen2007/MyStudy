### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int add(int a, int b) {
        vector<int> r{a,b};
        return std::accumulate(r.begin(), r.end(), 0);
    }
};
```