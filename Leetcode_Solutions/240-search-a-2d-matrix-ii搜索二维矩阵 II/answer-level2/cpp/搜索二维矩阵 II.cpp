### 解题思路
课上讲的是官方第四种方法，看了官方的其它解答，深有收获：
1、由坐下或右上边角开始，没判断一次与tag值，便可排除一列一行，不断逼近（临界点）
2、遍历对角线，每个对角线坐标只针对左边和上边，每判断一次与tag值，都可以排除之上或之左
3、切分成四个矩阵，中间数与tag每比较一次，排除一块。
其实个人觉得三种方法本质上都密切联系。

### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return 0;
        int a=matrix.size()-1;
        int b=0;
        while(a!=-1&&b!=matrix[0].size())
        {
            if(matrix[a][b]>target)
                a--;
            else if(matrix[a][b]<target)
                b++;
            else
                return true;
        } 
        return false;
    }
};
```
