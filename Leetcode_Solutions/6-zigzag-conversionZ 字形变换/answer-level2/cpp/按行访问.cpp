### 解题思路
首行和尾行每个周期值出现一个元素，中间行出现两次。
按照返回字符串的顺序遍历，每个元素被遍历一次，时间复杂度o(n), 其中n = len(s), 用到了常数个变量，空间复杂度o(1)

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string retStr;
        int cir = 2 * (numRows - 1);
        for(int i = 0; i < numRows; i++)
        {
            int ii = i;
            while(ii < s.size())
            {
                retStr += s[ii];
                if(i > 0 && i < numRows)
                {
                    // cout<< ii << " "<< cir - ii % cir + ii / cir * cir << endl;
                    int flag = cir - ii % cir + ii / cir * cir;
                    if(flag < s.size())
                    {
                        retStr += s[flag];
                    }
                }
                ii += cir;
            }
        }

        return retStr;
    }
};
```