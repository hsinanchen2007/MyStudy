### 解题思路
此处撰写解题思路
1、首先考虑两种简单的特殊情况：
（1）当numRows为0，返回空；
（2）当numRows为1，则返回[[1]];
2、当numRows大于1时，利用杨辉三角的特点，先把首尾的元素置为1，其余等于上一行的两个数字相加。
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> results;
        if(numRows == 0) //numRows为0
            return results;

        vector<int> vec = {1};
        if(numRows == 1) //numRows为1
        {
            results.push_back(vec);
            return results;
        }

        //numRows大于1
        results.push_back(vec); 
        for(int i = 1; i < numRows; i++)
        {
            vector<int> result(i+1);
            result[0] = 1;
            result[i] = 1;
            for(int j = 1; j < i; j++)
            {
                result[j] = results[i-1][j-1] + results[i-1][j];
            }
            results.push_back(result);
        }
        return results;
    }
};
```