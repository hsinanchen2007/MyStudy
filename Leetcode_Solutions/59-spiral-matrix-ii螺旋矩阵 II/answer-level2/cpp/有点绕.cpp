### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n);
        int left(0),right(n-1),top(0),down(n-1),num(1);
        while(1){//可以将二维数组都初始化为0，就不需考虑插入位置
                    //vector<vector<<int>>res(n,vector<int>(n,0));
            for(int i=left;i<=right;++i){
                res[top].insert(res[top].end()-left,num++);
            }if(++top>down)break;
            for(int i=top;i<=down;++i){
                res[i].insert(res[i].end()-left,num++);
            }if(--right<left)break;
            for(int i=right;i>=left;--i){
                res[down].insert(res[down].begin()+left,num++);
            }if(--down<top)break;
            for(int i=down;i>=top;--i){
                res[i].insert(res[i].begin()+left,num++);
            }if(++left>right)break;
        }
        return res;
    }
};
```