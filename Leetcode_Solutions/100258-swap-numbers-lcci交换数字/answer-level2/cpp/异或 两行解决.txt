### 解题思路
异或的性质

### 代码

```cpp
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0] ^= numbers[1] ^= numbers[0] ^= numbers[1];
        return numbers;
    }
};
```