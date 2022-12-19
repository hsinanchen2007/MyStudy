![image.png](https://pic.leetcode-cn.com/afa94339b8648958ed40904055b0a76524ea6a403c3e81ca3085d1cc47757340-image.png)

### 代码

```cpp
//动态规划
class Solution {
public:
    int fib(int N) {
        //当N=0，memo分配一个空间(memo[0])，memo[1]=1就会造成内存泄漏，所以当N=0时需要单独说明
        if(N==0) return 0;
        vector<int> memo(N+1,0);
        memo[1]=1;
        for(int i=2;i<=N;i++) 
            memo[i]=memo[i-1]+memo[i-2];
        return memo[N];
    }
};
//递归
class Solution
{
private:
    vector<int> memo;
    int Fib(int n)
    {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(memo[n] == -1)
            memo[n] = Fib(n-1)+Fib(n-2);
        return memo[n];
    }
public:
    int fib(int n)
    {
        memo = vector<int>(n+1,-1);
        return Fib(n);
    }
};
```
