### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> record;
    void circle(vector<vector<int>>& matrix,int starti,int startj,int m,int n){
        if(m<=0||n<=0) return;
        if(n==1){
             for(int i=starti;i<starti+m;i++) record.push_back(matrix[startj][i]);
             return ;
        }
        if(m==1){
            for(int j=startj;j<startj+n;j++) record.push_back(matrix[j][starti]);
            return ;
        }

        int i,j;
        for(i=starti;i<starti+m;i++) record.push_back(matrix[startj][i]);
        i--;
        for(j=startj+1;j<startj+n;j++) record.push_back(matrix[j][i]);
        j--;
        for(i=i-1;i>=starti;i--) record.push_back(matrix[j][i]);
        i++;
        for(j=j-1;j>startj;j--) record.push_back(matrix[j][i]);
        circle(matrix,starti+1,startj+1,m-2,n-2);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return   record;
        circle(matrix,0,0,matrix[0].size(),matrix.size());
        return record;
    }
};
```