### 解题思路
sort后输出第一个元素，用时较久

### 代码

```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        sort(numbers.begin(),numbers.end());
        return numbers[0];
    }
};
```