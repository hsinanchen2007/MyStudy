### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int sumNums(int n) {
        std::vector<int> data(n);
        std::iota(std::begin(data), std::end(data), 1);
        return std::accumulate(std::begin(data), std::end(data), 0);
    }
};
```