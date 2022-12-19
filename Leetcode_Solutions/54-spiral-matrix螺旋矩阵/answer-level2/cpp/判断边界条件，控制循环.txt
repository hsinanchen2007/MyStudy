### 解题思路
这道题和剑指offer中29题顺时针打印矩阵一样。先控制循环的圈数，再上右下左依次打印数据，  记得要判断循环的条件。。

### 代码

```cpp
class Solution {
public:
    // 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
    // 内存消耗 :6.6 MB, 在所有 C++ 提交中击败了100.00%的用户
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()==0) return res;
        if(matrix[0].size()==0) return res;
        int start = 0;//表示圈的入口
        while(matrix.size()>2*start&&matrix[0].size()>2*start){//循环控制条件。能转的圈数，
            spiralOrderCore(matrix, res, matrix.size(), matrix[0].size(), start);
            start++;
        }

        return res;
    }

    void spiralOrderCore(vector<vector<int>>& matrix, vector<int>& res, int m, int n, int start)
    {
        int endX = m-start;//先求到row的边界条件。
        int endY = n-start;//先求到clo的边界条件。
        //上，直接循环到endY
        for(int y = start;y<endY;++y){
            res.push_back(matrix[start][y]);
        }
        bool temp = false;
        //右
        if(start<endX){//此时要判断是否越界，避免这一圈只有一排数据，
            for(int x =start+1;x<endX;++x){
                temp = true;
                res.push_back(matrix[x][endY-1]);
            }
        }

        //下
        if(start<endY-1&&start<endX-1){//确保有下面这一排
            for(int y = endY-2;y>=start;--y){
                res.push_back(matrix[endX-1][y]);
            }
        }


        //左
        if(start<endX-2&&start<endY-1){//确保有中间一排，
            for(int x = endX-2;x>start;--x){
                res.push_back(matrix[x][start]);
            }
        }



    }
};
```