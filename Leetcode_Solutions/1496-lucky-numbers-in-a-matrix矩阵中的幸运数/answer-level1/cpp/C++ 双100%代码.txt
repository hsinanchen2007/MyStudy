
学习周赛第一的dalao的代码 C++ 耗时和空间均击败100%
```cpp
class Solution {
    int a[55],b[55];
    vector<int> ans;
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),i,j;
        memset(a,127,sizeof(a));//初始化，便于后面比较
        memset(b,0,sizeof(b));
        for(i=0;i<n;i++)for(j=0;j<m;j++)
        {
            a[i]=min(a[i],matrix[i][j]);
            b[j]=max(b[j],matrix[i][j]);
        }
        ans.clear();
        for(i=0;i<n;i++)for(j=0;j<m;j++)if(a[i]==matrix[i][j]&&b[j]==matrix[i][j])ans.push_back(matrix[i][j]);
        return ans;
    }
};
```