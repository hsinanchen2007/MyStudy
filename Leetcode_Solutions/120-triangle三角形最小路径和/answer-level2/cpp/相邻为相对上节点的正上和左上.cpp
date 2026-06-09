**特么你家的相邻是正上和左上，右上就不算了吗**
无fuck说
自己完成的动态规划题
![111.jpg](https://pic.leetcode-cn.com/91114eda8712b18a81574d738c324b0f7f472f19d63a642657838bd70754837e-111.jpg)



```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty() || triangle[0].empty()) return 0;
        if(triangle.size()==1) return triangle[0][0];
        vector<vector<int>> v;
        for(int i=0;i<triangle.size();++i)
        {
            vector<int> temp(i+1,0);
            v.push_back(temp);
        }
        v[0][0]=triangle[0][0];
        v[1][0]=v[0][0]+triangle[1][0];
        v[1][1]=v[0][0]+triangle[1][1];
        if(triangle.size()==2) return v[1][0]<v[1][1]?v[1][0]:v[1][1];
        int result=INT_MAX;
        for(int i=2;i<triangle.size();++i)
        {
            for(int j=0;j<=i;++j)
            {
                int a=0;
                if( j==0 )
                {
                    a=v[i-1][0];
                    v[i][j]=a+triangle[i][j];
                }
                else if(j>=1 && j<=i-1)
                {
                    a=v[i-1][j-1]<v[i-1][j]?v[i-1][j-1]:v[i-1][j];
                    v[i][j]=a+triangle[i][j];
                }
                else 
                {
                    a=v[i-1][j-1];
                    v[i][j]=a+triangle[i][j];
                }
                if(i==triangle.size()-1)
                {
                    result=min(result,v[i][j]);
                }
            }
            
        }
        return result;
    }
};
```
