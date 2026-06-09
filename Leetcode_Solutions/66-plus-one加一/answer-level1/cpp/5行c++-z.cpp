### 解题思路
追求代码行数尽可能少，可读性较差，不太清楚的朋友可以先看我另一个简单的解答
https://leetcode-cn.com/problems/plus-one/solution/c-z-by-zrita/

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        for(int i=digits.size()-1;i>=0;i--)
            if(++digits[i] %=10)  //只有当该位为9时，对10取余得0，才会跳过if语句继续循环
                return digits;

        digits.insert(digits.begin(), 1);   //如果首位也产生进位,才会执行到这条语句，否则循环中已经return了
        return digits;
    }
};
```