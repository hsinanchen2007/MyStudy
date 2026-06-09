结论：只要取出数的位置不相邻，那么一定有一种顺序全取出来
证明：对于任意不相邻的取法，我们可以把要取的数和它右边的数字绑定在一起，数组从3n变为2n,问题转化为了,2n个数字任意取n个数，能否与左边没有被取的数字匹配。此时找到最左边的一个取出来的数（带循环的，走到0之后就到2n的位置），那么它左边一定是空白，和它匹配，消去，剩下2n-2个数字也是如此做，如此往复，最后剩下两个，也一定可以这样做。问题得证。

那么剩下的就是可以解的简单的不相邻子序列求最大和，注意：我假设最后一个元素不取，所以要做两次。

```
#define sz size()
class Solution {
    int dp[505][505][2];
    
public:
    int maxSizeSlices(vector<int>& s) {
        int ans =0;
        for(int k=0;k<2;k+=1)
        {
            memset(dp,0,sizeof dp);
            dp[1][1][1]=s[k%s.sz];
            for(int i=2;i<=s.size();i++)
                for(int j=1;j<=s.size()/3;j++)
                {
                    dp[i][j][0] = max(dp[i-1][j][0],dp[i-1][j][1]);
                    dp[i][j][1] = dp[i-1][j-1][0]+s[(i-1+k)%s.sz];
                }
            ans = max(ans, dp[s.sz][s.sz/3][0]);
        }
        return ans;
    }
};
```
![image.png](https://pic.leetcode-cn.com/a8a118c779a00631ab2d01370ea431b31e74575179a11875ee0e60495b960a24-image.png)

