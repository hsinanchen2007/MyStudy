### 解题思路
就是按照人走的思想，逐渐缩小围墙，并且注意空矩阵和x*1的矩阵
### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans={};
        int pos_i=0;
        int pos_j=0;
        int len=0;
        int flag=0;//flag=0,向右，flag=1,向下，flag=2，向左，flag=3,向上
        int max_i=matrix.size()-1;
        if(max_i==-1){
            return ans;//为了防止空矩阵
        }
        int max_j=matrix[0].size()-1;
        if(max_j==0){
            flag=1;//为了防止x*1的矩阵
        }
        int len_max=matrix.size()*matrix[0].size();
        int min_i=1;
        int min_j=0;
        while(len<len_max){
            ans.push_back(matrix[pos_i][pos_j]);
            len++;
            switch (flag)
            {
            case 0:
                pos_j++;
                if(pos_j >= max_j){
                    max_j--;
                    flag++;
                }
                break;
            case 1:
                pos_i++;
                if(pos_i>=max_i){
                    max_i--;
                    flag++;
                }
                break;
            case 2:
                pos_j--;
                if(pos_j<=min_j){
                    min_j++;
                    flag++;
                }
                break;
            case 3:
                pos_i--;
                if(pos_i<=min_i){
                    min_i++;
                    flag=0;
                }
                break;
            default:
                break;
            }
        }
        return ans;
    }
};
```