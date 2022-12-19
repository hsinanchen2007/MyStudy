### 解题思路
找到正确的遍历数组的方法即可解题，很简单

### 代码

```cpp
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        //检查矩阵对角线和上三角元素
        for(int j = 0; j < matrix[0].size(); j++)
        {
            int a = matrix[0][j];   //选取第 0 行的第 j 个元素，依次和对角线上的元素比较      
            //保存i  
            int k = j;
            // j + 1
            j += 1;
            for(int i = 1; i < matrix.size() && j < matrix[0].size(); i++, j++)
            {
                //对角线上有元素不相等
                if(matrix[i][j] != a)
                    return false;
            }
            //j 复位
            j = k;

        }

        //检查下三角
        for(int i = 1; i < matrix.size(); i++)
        {
            //选取第 0 列的第 i 个元素作为基本的比较元素
            int a = matrix[i][0];
            // k 保存当前的i值
            int k = i;
            //i 加 1
            i++;
            for(int j = 1; i < matrix.size() && j < matrix[0].size(); i++, j++)
            {
                //对角线上有元素不相等
                if(matrix[i][j] != a)
                    return false;
            }
            // i 复位
            i = k;
        }
        return true;
    }
};
```