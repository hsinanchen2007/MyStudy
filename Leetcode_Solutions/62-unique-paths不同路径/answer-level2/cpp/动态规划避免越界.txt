### 解题思路
其实是个数学问题，总共向下走m-1次，向右走n-1次，相当于把m-1个黑球和n-1个
白球排成一排，问有多少种方法。一共有m+n-2个位置，把m-1个黑球放进去，剩下的
就是白球，所以一共有C(m+n-2,m-1)种方法。但是用递推计算组合数的时候可能会产生
过大的数，所以可以用动态规划来避免。

### 代码

```cpp
class Solution {
public:
    int com(int a,int b){
        if(a==b||b==0)return 1;
        if(b==1)return a;
        return com(a-1,b-1)*a/b;
    }
    int uniquePaths(int m, int n) {
        vector<int>c(n,1);
        int i,j;
        for(i=1;i<m;i++){
            for(j=1;j<n;j++)c[j]+=c[j-1];
        }
        return c[n-1];
    }
};
```