### 解题思路
应用算法导论中的思路，创建一个边界全为0的数组，将这些边界作为动态规划的最小子问题，然后自底向下根据递归式写算法

### 代码

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int length1=text1.size();
        int length2=text2.size();
        int c[length1+1][length2+1];
        for(int i=1;i<=length1;i++)
        {
            c[i][0]=0;
        }
        for(int i=0;i<=length2;i++)
        {
            c[0][i]=0;
        }
        for(int i=1;i<=length1;i++)
       { for(int j=1;j<=length2;j++)
        {
            if(text1[i-1]==text2[j-1])
           { 
               c[i][j]=c[i-1][j-1]+1;
           }
            else
            {
                c[i][j]=max(c[i-1][j],c[i][j-1]);   
                }
        }
       }
        return c[length1][length2];
    }
    
};

```