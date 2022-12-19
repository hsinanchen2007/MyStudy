### 解题思路
倒序遍历，
加一判断，
yes return，
no 循环，
循环结束，
头前插一，
return 结束。
### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       for (int i = digits.size() - 1; i >= 0; --i)
        {
            if ((++digits[i] %= 10) != 0)return digits;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
```