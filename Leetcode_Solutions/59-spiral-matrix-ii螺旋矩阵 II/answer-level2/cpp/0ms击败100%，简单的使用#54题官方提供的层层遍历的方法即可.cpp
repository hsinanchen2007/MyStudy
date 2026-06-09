### 解题思路
由题知矩阵为正方形矩阵，故其中元素刚好放满1-n^2的元素；
使用四个边界指针，通过顺时针遍历最外层位置以及更新边界指针的方式进行遍历，当上下、左右的边界指针相遇时则跳出循环

示意：
-----→
↑    |
|    |
|    |
←----↓
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int a = 0;
        int b = 0;
        int c = n - 1;
        int d = n - 1;  //定义上下左右4个边界
        int count = 0;  //定义用于表示数组元素的count，其范围是1-n^2，大小范围由数组大小控制
        while(true)
        {
            for(int i = a; i <= c; ++i){
                ++count;
                ans[b][i] = count;
            }; //向右
            if(++ b > d) break; //重新设定上边界
            for(int i = b; i <= d; ++i){
                ++count;
                ans[i][c] = count;
            }; //向下
            if(-- c < a) break; //重新设定有边界
            for(int i = c; i >= a; --i){
                ++count;
                ans[d][i] = count;
            }; //向左
            if(-- d < b) break; //重新设定下边界
            for(int i = d; i >= b; --i){
                ++count;
                ans[i][a] = count;
            }; //向上
            if(++ a > c) break; //重新设定左边界
        }
        return ans;
    }
};
```