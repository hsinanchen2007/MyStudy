### 解题思路
由于单纯递归的话，根据递归树可以看出有很多值有重复计算的情况，会使得时间复杂度不符合要求。改进的话，就是保存每一次计算的值然后把计算过的去除掉那么就可以避免递归导致的时间复杂度指数增长的情况。也可以用动态规划的方法写出来，时间复杂度为O(N)
### 代码

```cpp
class Solution {
public:
    int solve(int n,int *mem)
    {
      if(mem[n]>=0)
      return mem[n];
      if(n==0)
      {
          mem[n]=0;
          return mem[n];
      }
      if(n==1)
      {
          mem[n]=1;
          return mem[n];
      }
      if(n==2)
      {
        mem[n]=1;
        return mem[n];
      }
      mem[n]=solve(n-3,mem)+solve(n-2,mem)+solve(n-1,mem);
      return mem[n];
    }
    int tribonacci(int n) {
        int *mem=new int[n+1];
        for(int i=0;i<=n;i++)
        mem[i]=-1;
        return solve(n,mem);
    }
};
```