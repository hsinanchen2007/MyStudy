class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        res.resize(numRows);
        if(numRows == 0)
            return res;
        for(int i=0; i<numRows; i++)
        {
            res[i].resize(i+1,1);
            for(int j=1; j<i; j++)
            {
                res[i][j]=res[i-1][j-1]+res[i-1][j];
            }
        }
        return res;
    }
};
![image.png](https://pic.leetcode-cn.com/12b6c2dd80ea54b415d25f301f4b60e55f08014f9d76254a4f8010aea15f3660-image.png)

