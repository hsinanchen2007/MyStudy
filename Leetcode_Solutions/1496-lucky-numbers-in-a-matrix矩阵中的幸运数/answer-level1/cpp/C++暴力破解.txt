### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int> result;
        for(int i=0;i<m;++i)//行开始比较，次数也是行标
        {
            int min=matrix[i][0],max_pos=0;
            for(int j=1;j<n;++j)
            {
                if(matrix[i][j]<min)//换出小的
                {
                    min=matrix[i][j];
                    max_pos=j;//列号
                }
            }
            int max=min,flag=0;
            for(int k=0;k<m;++k)
            {
                if(matrix[k][max_pos]<max||k==i)
                {
                    continue;
                }
                else{
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                result.push_back(min);
            }
        }
        return result;
    }
};
```