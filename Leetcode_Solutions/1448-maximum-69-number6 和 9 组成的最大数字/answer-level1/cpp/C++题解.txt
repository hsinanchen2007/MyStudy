### [1323. 6 和 9 组成的最大数字](https://leetcode-cn.com/problems/maximum-69-number/)

#### 题解
  + 从后向前扫描，将最前面的一个6变成9
  + 假设并更正，记录差值，详见代码
  + 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)

#### 代码

```cpp
class Solution {
public:
    int maximum69Number (int num) {
        int res = 0, p = 1, dt = 0;
        while(num)
        {
            if(num%10 == 9) res += p*(num%10);
            else {
                res += (p*9 - dt);
                dt = p*3;
                }
            num /= 10;
            p *= 10;
        }
        return res;
    }
};
```