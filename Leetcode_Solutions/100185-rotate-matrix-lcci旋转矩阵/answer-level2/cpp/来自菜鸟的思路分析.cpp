### 解题思路
此处撰写解题思路
![图片.png](https://pic.leetcode-cn.com/94bdcb64f0cdf2447fdd6aa1702279ad929d5f4c4c75e0c77bbf9954e021b544-%E5%9B%BE%E7%89%87.png)
运用了reverse函数，算是种投机取巧的方法吧，理解思路就好了
### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        //求逆
        for (int i = 0;i<N;++i)
        {
            for(int j = i+1;j<N;++j)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;

            }

        }
        //每行数组翻转
        for(int i=0;i<N;++i)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        

    }
};
```