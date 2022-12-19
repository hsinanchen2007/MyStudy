### 解题思路
当时WA了半天，WA在了vector的下标上面，vector<vector<int>>的第二维可以理解为组内的顺序，第一维是组数。
还有一点需要注意的是，第一次刷，没有注意到特殊情况需要注意if(matrix.size()==0)  return false;
eg. [] 0结果是0

### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // cout<<matrix.size()<<" "<<matrix[0].size();
        if(matrix.size()==0)
            return false;
        return find(matrix,matrix[0].size()-1,0,target);
    }
    bool find(vector<vector<int>>& matrix,int i,int j,int tar){
        // cout<<i<<" "<<j<<endl;
        if(i<0 || j>(matrix.size()-1))
            return false;
        else if (matrix[j][i]==tar)
            return true;
        else if(matrix[j][i]>tar)
            return find(matrix,i-1,j,tar);
        else
            return find(matrix,i,j+1,tar);
    }
};
```