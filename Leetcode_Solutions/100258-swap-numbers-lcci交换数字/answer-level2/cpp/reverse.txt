### 解题思路
reverse

### 代码

```cpp
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        reverse(numbers.begin(), numbers.end());
        return numbers;
    }
};
```