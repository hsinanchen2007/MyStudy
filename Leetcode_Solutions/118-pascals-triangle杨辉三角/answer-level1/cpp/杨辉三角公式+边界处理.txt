杨辉三角迭代公式` res[i][j]=res[i-1][j-1]+res[i-1][j]`
边界情形：
* 必须要有前一行.即 (i-1)>=0
* 边界值的判断 j不能处在当前行的第一列和最后一列(0<j<i)，否则没有前驱元素
```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0;i<numRows;++i)
        {
            vector<int> tmp;
            for(int j=0;j<=i;++j)
            {
                if((i-1)>=0 && j>0 && j<i)  tmp.push_back(res[i-1][j-1]+res[i-1][j]);
                else tmp.push_back(1);
            }
            res.push_back(tmp);
        }
        return res;
    }
};