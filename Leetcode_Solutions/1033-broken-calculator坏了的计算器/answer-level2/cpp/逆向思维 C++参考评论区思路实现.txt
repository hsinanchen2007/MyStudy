### 解题思路
第一眼没什么思路，只想到可能会动态规划，看了看评论区，看到用到逆向思维
    将y看作只可能除二、加一， 不得不佩服大佬们的思路就是简洁
    于是:
    if(x == y)  返回步数
    if(x>y)     那么y只能够执行加一操作，要执行所少次，就是x-y差值
    if（x<y）   y尽可能凑够满足执行除二操作条件（y 为偶数才能执行除二操作），
### 代码

```cpp
class Solution {
public:
    int step = 0;
    int brokenCalc(int X, int Y) {
        while(Y>X)
        {
            if(Y%2 == 0) Y/=2;
            else Y++;
            step++;
        }
        return step+X-Y;  
    }
};
```