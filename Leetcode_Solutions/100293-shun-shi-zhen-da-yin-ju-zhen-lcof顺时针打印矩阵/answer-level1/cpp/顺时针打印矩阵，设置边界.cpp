将上下左右边界表示的清楚一些
上边界 up
下边界 down
左边界 l
有边界 r

++a>b 表示先自增，然后比较
```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int> res;
         if(matrix.empty())
         return res;
         int l=0,r=matrix[0].size()-1; //左右边界
         int up=0,down=matrix.size()-1;//上下边界

         while(1)
         {
             for(int i=l;i<=r;i++) res.push_back(matrix[up][i]);
             if(++up>down) break;
             for(int i=up;i<=down;i++) res.push_back(matrix[i][r]);
             if(--r<l) break;
             for(int i=r;i>=l;i--) res.push_back(matrix[down][i]);
             if(--down<up) break;
             for(int i=down;i>=up;i--) res.push_back(matrix[i][l]);
             if(++l>r) break;
         }
        
         return res;
    }
};
```
