由杨辉三角定义可得，下一行的数由上一行相邻两数作和得到，简单的迭代即可

然而观察可知，杨辉三角的值是左右对称的，故而每一行只需要算一半就行，剩下一半直接对称过去，这样可以节省一半时间

代码：
```
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0 ; i < numRows ; i++) {
            vector<int> temp(i + 1);
            temp[0] = 1;
            if(i) {
                for(int j = 1 ; j <= (i >> 1); j++)
                    temp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
                for(int j = (i >> 1) + 1 ; j <= i ; j++)
                    temp[j] = temp[i - j];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
```
