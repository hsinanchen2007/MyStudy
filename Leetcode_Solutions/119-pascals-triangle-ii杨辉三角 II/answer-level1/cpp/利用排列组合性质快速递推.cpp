### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :7.7 MB, 在所有 C++ 提交中击败了100.00%的用户
利用排列组合的性质
* 1. 杨辉三角rowIndex相当于:C{0, rowIndex+1}->C{rowIndex+1, rowIndex+1}
* 2. 杨辉三角前后对称
* 3. C{m, n}既可以用阶乘运算也可以通过C{m-1,n}递推
最后注意一下int内存溢出
### 代码

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        for (int i = 0; i < rowIndex + 1; i++)
        {
            if (i == 0)
            {
                row.push_back(1);
            }
            else if (i <= (rowIndex + 1) / 2)
            {
                double tmp = (double)row[i - 1] * (rowIndex - i + 1) / i;
                row.push_back(round(tmp));
            }
            else if (i > (rowIndex + 1) / 2)
            {
                row.push_back(row[rowIndex - i]);
            }
        }
        return row;
    }
};
```