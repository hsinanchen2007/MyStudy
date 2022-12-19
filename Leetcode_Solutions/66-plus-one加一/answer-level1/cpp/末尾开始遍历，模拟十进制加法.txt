### 解题思路
思路很简单，模拟十进制加法。

难点在于应该先+1再判断，而不是先判断再+1；
当循环分支过于复杂，应该尝试考虑反常规的操作；

跳出循环体的判断也很重要。

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i=digits.size()-1; i>=0; --i) {
            ++ digits[i];
            if (digits[i] != 10) return digits;
            else digits[i] = 0; // 难点在这里：不需要更多操作，直接继续循环操作上一位
        }
        digits.insert(digits.begin(), 1); //如果执行到此，说明首位一定被加到10了，不然就直接return了
        return digits;
    }
};
```

这题应该还有递归的写法