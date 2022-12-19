### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
       return *std::min_element(std::begin(numbers), std::end(numbers));
    }
};
```