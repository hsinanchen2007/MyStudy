### 解题思路
此处撰写解题思路

### 代码
递推公式见 注释
如果用数组应该会快不少

```cpp
class Solution {
    int min(int x,int y,int z)
    {
        int t=x>y?y:x;
        t=t>z?z:t;
        return t;
    }
public:
    int minDistance(string word1, string word2) {
        //三个操作都可以让一个字符变得相同
        //求最大的重叠
        //dp[m][n] length(word1)==m length(word2)==n 的最大重叠
        //dp[m+1][n+1] 
        //相等的话dp[m+1][n+1]=dp[m][n]
        //不相等dp[m+1][n]+1 dp[m][n+1]+1 dp[m][n]+1
        int nSize1=word1.size();
        int nSize2=word2.size();
        if(nSize1==0)
        {
            return nSize2;
        }
        if(nSize2==0)
        {
            return nSize1;
        }
        vector<vector<int>> vdp;
        vector<int> row;
        //nSize1+1作为行数
        //nSize2+1作为列数
        row.resize(nSize2+1);
        for(int  i=0;i<=nSize1;++i)
        {
            vdp.push_back(row);
        }
        //进行初始化
        for(int  i=0;i<=nSize1;++i)
        {
            vdp[i][0]=i;
        }
        for(int  i=0;i<=nSize2;++i)
        {
            vdp[0][i]=i;
        }
        //然后进行运算
        //右边的三角
        for(int i=1;i<=nSize1;++i)
        {
            //得从1开始，不然没值了
            for(int j=1;j<=nSize2;++j)
            {
                if(word1[i-1]==word2[j-1])
                {
                    vdp[i][j]=vdp[i-1][j-1];
                }
                else
                {
                    vdp[i][j]=min(vdp[i-1][j-1]+1,vdp[i-1][j]+1,vdp[i][j-1]+1);
                }
            }
        }
        return vdp[nSize1][nSize2];
    }
};
```