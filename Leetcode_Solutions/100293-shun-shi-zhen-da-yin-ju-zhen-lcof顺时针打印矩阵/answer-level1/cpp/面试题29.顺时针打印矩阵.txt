### 解题思路
核心思路：设置四个整数标记四个边界，打印矩阵的过程看成四步，每一步打印一个方向的一行并调整边界值，检测到两个边界重合时停止
执行用时 :24 ms, 在所有 C++ 提交中击败了11.33%的用户
内存消耗 :9.4 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0)return {};
        int size=matrix.size()*matrix[0].size();
        vector<int>result(size,0);
        int count=0;
        int top=0,left=0,bottom=matrix.size(),right=matrix[0].size();
        while(1){
            if(top!=bottom&&left!=right){
                for(int i=left;i<right;i++){
                    result[count++]=matrix[top][i];
                }
                top++;
            }
            else break;
            if(top!=bottom&&left!=right){
                for(int i=top;i<bottom;i++){
                    result[count++]=matrix[i][right-1];
                }
                right--;
            }
            else break;
            if(top!=bottom&&left!=right){
                for(int i=right-1;i>=left;i--){
                    result[count++]=matrix[bottom-1][i];
                }
                bottom--;
            }
            else break;
            if(top!=bottom&&left!=right){
                for(int i=bottom-1;i>=top;i--){
                    result[count++]=matrix[i][left];
                }
                left++;
            }
            else break;
        }
        return result;
    }
};
```