### 解题思路
杨辉三角：从第三行开始，除去首尾元素以外，当前数等于左上方和右上方元素之和。
1.外层大循环从第1行循环到第n行，每处理完一行就将这一行的值都保存到结果中
2.内存循环j的值从0到i(可以取到i)，所谓每行首尾元素翻译成代码即j=0或者j=i时，这时也包括了前两行值都为1的情况。
3.第三行开始，当前数等于左上方和右上方元素之和，翻译成代码就是res[i-1][j] + res[i-1][j-1]


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0)
        {
            return res;
        }

        for(int i = 0;i < numRows;i++)
        {
            vector<int>row;//每一行的数字
            for(int j = 0;j <= i;j++)
            {
                if(j == 0||j == i)
                {
                    row.push_back(1);//每一行的第一个数都是1
                }    
                else//上一行的两个值相加
                {
                    row.push_back(res[i-1][j] + res[i-1][j-1]);
                }
            }
            res.push_back(row);//res按行保存
        }
        return res;
    }
};
```