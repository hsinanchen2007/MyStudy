### 解题思路
对于方法二，思路就是：
对于m*n的矩阵，即m行，n列，设定一个数组来存放，到了第n列时候的所有排列，例如dp[1]表示到了第二列时所能产生的所有排列手段
![帆帆帆帆.png](https://pic.leetcode-cn.com/fdba6fee509df7c595d7748dec87b58aef4907242f81c5132594c474f32177dc-%E5%B8%86%E5%B8%86%E5%B8%86%E5%B8%86.png)



### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        //用数学方法求解:相当于是求从S个位置里面，找出D个位置的排列组合个数
        //即C(S,D)
        // int S = m+n-2; // 总共移动的步数
        // int D = m-1;  //向下移动的步数
        // long ret=1;
        // for(int i= 1;i<=D;i++)
        // {
        //     ret = ret*(S-D+i)/i;
        // }
        // return (int)ret;
        //方法二  递归法
        vector<int> dp(n,1);
        
        for(int i=1;i<m;i++)
        {
            for(int j = 1;j<n;j++)
            {
                dp[j] = dp[j]+dp[j-1];
            }
        }
        return dp[n-1];
    }
};
```