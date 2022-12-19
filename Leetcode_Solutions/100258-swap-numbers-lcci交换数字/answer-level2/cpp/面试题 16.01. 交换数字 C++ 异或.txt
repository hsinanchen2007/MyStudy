### 解题思路
a ^ b ^ b = a
a ^ b ^ a = b

a ^ a = 0
0 ^ a = a
异或满足交换律 结合律


### 代码

```cpp
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers.at(0) = numbers.at(0) ^ numbers.at(1);
        numbers.at(1) = numbers.at(0) ^ numbers.at(1);
        numbers.at(0) = numbers.at(0) ^ numbers.at(1);
        return numbers;
    }
};
```