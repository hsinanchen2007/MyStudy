### 解题思路
也是模拟打印顺序，右 -> 下 -> 左 -> 上， 每打印一次，做一次continue操作，执行下一次循环操作，唯一需要注意的是，当向上走的时候，因为缺少约束条件，所以人为的加了一个一直向上的小循环。

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> arr;
        if(matrix.empty())
            return arr;
        int len = matrix.size();
        int wid = matrix[0].size();
        int flag[100][100] = {0};
        int i = 0, j = 0;
        bool sign = true;
        while(sign){
            if((i < len) && (j < wid))  //打印
                if(flag[i][j] == 0){
                    arr.push_back(matrix[i][j]);    //  aaaaaaaaaaaaaaaaaaa md 生气
                    flag[i][j] = 1;
                }
            if((j+1) < wid)   // 向右
                if(flag[i][j+1] == 0){
                    j++; continue; }
            if((i+1) < len)   //向下
                if(flag[i+1][j] == 0){
                    i++; continue; }
            if(j > 0)         //向左
                if(flag[i][j-1] == 0){
                    j--; continue; }
            if(i > 0)         //向上
                if(flag[i-1][j] == 0)
                    while(flag[i-1][j] == 0){
                        i--; 
                        arr.push_back(matrix[i][j]);   
                        flag[i][j] = 1;
                    }
            if(arr.size() == len * wid)   //结束条件
                sign = false;
        }
        return arr;
    }
};
```