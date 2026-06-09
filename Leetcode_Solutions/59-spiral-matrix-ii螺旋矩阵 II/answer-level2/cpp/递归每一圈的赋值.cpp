### 解题思路
把每一圈的赋值写成一个递归函数

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        generateMatrix_recursive(res,0,0,n,1);

        return res;
    }

    void generateMatrix_recursive(vector<vector<int>>&res,int startRow,int startCol,int n,int count)
    {
        if(n == 1)
        {
            res.at(startRow)[startCol] = count;
            return;
        }
        if(n == 0) return;

        int endRow = startRow+n;
        int endCol = startCol+n;
        for(int i=startCol;i<endCol;++i)
        {
            res.at(startRow)[i] = count++;
        }
        for(int i=startRow+1;i<endRow;++i)
        {
            res.at(i)[endCol-1] = count++;
        }
        for(int i=endCol-2;i >= startCol;--i)
        {
            res.at(endRow-1)[i] = count++;
        }
        for(int i=endRow-2;i > startRow;--i)
        {
            res.at(i)[startCol] = count++;
        }
        generateMatrix_recursive(res,startRow+1,startCol+1,n-2,count);
    }
};
```