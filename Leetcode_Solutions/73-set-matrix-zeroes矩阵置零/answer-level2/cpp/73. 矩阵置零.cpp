先统计哪些行、列需要置零，统计完后就置零。

```
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        unordered_set<int> lines,rows;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    lines.insert(i);
                    rows.insert(j);
                }
            }
        }
        
        for(unordered_set<int>::iterator it=lines.begin();it!=lines.end();it++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[*it][j]=0;
            }
        }
        for(unordered_set<int>::iterator it=rows.begin();it!=rows.end();it++)
        {
            for(int i=0;i<m;i++)
            {
                matrix[i][*it]=0;
            }
        }
    }
};
```
