### 解题思路
此处撰写解题思路

### 代码

```cpp

class Solution {
public:
    int numWays(int n) {
        long a = 1,b = 1, t;
        if(n == 0)  return 1;
        if(n == 1)  return 1;
        for(int i = 2 ; i <= n; i++)
        {
            t = (a + b) % 1000000007;
            a = b;
            b = t;
        }
        return b;
    }
};

```
/*
对于f(n) 考虑最后2种情况，若青蛙最后跳1阶，则为f(n-1) 
                        若青蛙最后跳2阶，则为f(n-2) 
所以f(n)=f(n-1)+f(n-2)
出口为n = 0 -> 1;  n = 1 -> 1
利用ab记录，求和递归，减少了一般递归的重复计算 