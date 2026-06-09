1. 先不考虑边界问题，同一曼哈顿距离的所有单元格，围成一个只含四条边的正方形
1. 将正方形等分成四段处理，注意四个顶点单元格不要重复处理
1. 往vector中插入时，注意判断单元格是否符合条件，即判断单元格是否在矩阵范围内

- 优点：直接插入，不需要使用排序算法
- 缺点：逻辑稍微复杂，需判断单元格是否在矩阵范围内

```
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>{r0, c0});

        //通过给出坐标的单元格到矩阵四个定点的距离，获取最远距离
        int dist = max(max(r0 + c0, r0 + C - c0), max(R - r0 + c0, R - r0 + C - c0));

        /*
        //矩阵示例，"OO"表示给出坐标的单元格，"oo"表示未处理的单元格
        //"2b"中，"2"表示曼哈顿距离，"b"表示代码对应的分组
        oo oo oo 3b oo oo oo
        oo oo 3a 2b 3b oo oo
        oo 3a 2a 1b 2b 3b oo
        3a 2a 1a OO 1c 2c 3c
        oo 3d 2d 1d 2c 3c oo
        oo oo 3d 2d 3c oo oo
        oo oo oo 3d oo oo oo
        */
        int bufR, bufC;
        for(int i = 1; i <= dist; i++)
        {
            for(int j = 0; j < i; j++)
            {
                //左上(a)：从左顶点到上定点（不含）
                bufR = r0 - i + j, bufC = c0 - j;
                if(bufR >= 0 && bufC >= 0)
                    ans.push_back(vector<int>{bufR, bufC});
                
                //右上(b)：从上顶点到右定点（不含）
                bufR = r0 + j, bufC = c0 - i + j;
                if(bufR < R && bufC >= 0)
                    ans.push_back(vector<int>{bufR, bufC});
                
                //右下(c)：从右顶点到下定点（不含）
                bufR = r0 + i - j, bufC = c0 + j;
                if(bufR < R && bufC < C)
                    ans.push_back(vector<int>{bufR, bufC});
                
                //左下(d)：从右顶点到下定点（不含）
                bufR = r0 - j, bufC = c0 + i - j;
                if(bufR >= 0 && bufC < C)
                    ans.push_back(vector<int>{bufR, bufC});
            }
        }
    
        return ans;
    }
};
```

- PS：总感觉for循环里的计算量能优化一下，只是未及仔细想，后续有想法再做处理吧！