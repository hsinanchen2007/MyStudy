### 解题思路
此处撰写解题思路
青蛙跳台阶按照问题拆解原则可以拆解成和斐波那契数列一样的问题，斐波那契数列可以使用动态规划来求解，但是求的是和
青蛙跳台阶求的是几种跳法 而f(n)的跳法 就等于 f(n-1)的跳法数加上 f(n-2) 符合斐波那契数列求和规则
然后纸上演算0-4阶跳法也是符合这个规律的，所以有时候纸上画一画也是很有用的。

### 代码

```cpp
class Solution {
public:
    int numWays(int n) {
        if(n==0) return 1;
        if(n==1) return 1;

        int Step1 = 1,Step2 = 2;
        int Res = 0;
        for(int i=2;i<=n;i++)
        {
            Res = (Step1 + Step2) % 1000000007;
            Step1 = Step2;
            Step2 = Res;
        }

        return Res;
    }
};
```