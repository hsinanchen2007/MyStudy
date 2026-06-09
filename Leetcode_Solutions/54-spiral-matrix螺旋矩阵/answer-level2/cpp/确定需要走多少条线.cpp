### 解题思路
根据矩阵的形状确定需要需要拐多少次或者需要走多少次，设置各个节点的变化条件。
这里我觉得代码还有优化的空间，每个遍历过程用do while可能更好一点

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res={};
        if(matrix.empty()){
            return res;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        
        if(m==1) return matrix[0];
        if(n==1){
            for(int i=0;i<m;i++){
                res.push_back(matrix[i][0]);
            }
            return res;
        }
        int temp;
        int t = 0;
        int tempm = 0;
        int tempn = 0;
        res.push_back(matrix[0][0]);
        if(m<=n){
            temp = 2*m-1;
        }
        else{
            temp = 2*n;
        }
        for(int i=0;i<temp;i++){
            t = (i+1)/4;
            if(i%4==0){
                tempn = tempn + 1;
                for(;tempn<n-t;tempn++){
                    res.push_back(matrix[tempm][tempn]);
                }
                tempn = tempn - 1;
            }
            else if(i%4==1){
                tempm = tempm + 1;
                for(;tempm<m-t;tempm++){
                    res.push_back(matrix[tempm][tempn]);
                }
                tempm = tempm - 1;
            }
            else if (i%4==2){
                tempn = tempn - 1;
                for(;tempn>=t;tempn--){
                    res.push_back(matrix[tempm][tempn]);
                }
                tempn = tempn + 1;
            }
            else{
                tempm = tempm - 1;
                for(;tempm>=t;tempm--){
                    res.push_back(matrix[tempm][tempn]);
                }
                tempm = tempm + 1;
            }
        }
        return res;
    }
};

```