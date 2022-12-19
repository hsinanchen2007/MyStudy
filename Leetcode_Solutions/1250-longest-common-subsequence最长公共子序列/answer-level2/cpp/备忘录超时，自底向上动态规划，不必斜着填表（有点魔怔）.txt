### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> a;
        int m=text1.length(),n=text2.length(); 
        vector<int> b;
         for(int j=0;j<=n;j++)
        {
            b.push_back(0);
        }
        for(int i=0;i<=m;i++)
        {
        a.push_back(b);
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    a[i][j]=a[i-1][j-1]+1;
                }
                else a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
        return a[m][n];
    }
   
};
```