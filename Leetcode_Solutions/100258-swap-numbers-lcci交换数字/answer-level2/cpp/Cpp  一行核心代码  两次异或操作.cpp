### 解题思路
异或

### 代码

```cpp
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0]=numbers[0]^numbers[1]^(numbers[1]=numbers[0]);
        return numbers;
    }
};
```