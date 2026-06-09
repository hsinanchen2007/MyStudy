### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :9.5 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
    	numbers[0] = numbers[0] ^ numbers[1];
    	numbers[1] = numbers[0] ^ numbers[1];
    	numbers[0] = numbers[0] ^ numbers[1];
    	return numbers;
    }
};
```