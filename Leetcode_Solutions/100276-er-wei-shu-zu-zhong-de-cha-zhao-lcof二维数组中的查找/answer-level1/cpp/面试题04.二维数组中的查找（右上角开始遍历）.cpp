### 解题思路
核心要点：从二维数组右上角开始与target比较，不断调整i，j，类似二分查找，但是是二维的
执行用时 :52 ms, 在所有 C++ 提交中击败了16.73%的用户
内存消耗 :14.6 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0){
            return false;
        }
        int rows=matrix.size();
        int cols=matrix[0].size();
        for(int i=0,j=cols-1;i<rows&&j>=0;){
            if(matrix[i][j]==target){
                return true;
            }
            else{
                if(matrix[i][j]<target){
                    i++;
                }
                else{
                    j--;
                }
            }
        }
        return false;
    }
};
```