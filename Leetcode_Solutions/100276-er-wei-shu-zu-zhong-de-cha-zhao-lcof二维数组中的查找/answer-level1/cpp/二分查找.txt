### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if( matrix.size()==0)return false;
        for(int i=0;i<matrix.size();i++){
            int low=0,high=matrix[i].size()-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(matrix[i][mid]==target)return true;
                else if(matrix[i][mid]>target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        }
        return false;
    }
};
```