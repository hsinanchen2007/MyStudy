```
/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        string res = "";
        int step = (numRows - 1) * 2;
        for (int i = 0; i < numRows; i++)
        {
            int index = i;
            int skip = (numRows - 1 - i) * 2;
            while (index < s.length())
            {
                res += s[index];
                if (i != 0 && i != numRows - 1 && index + skip < s.length())
                    res += s[index + skip];
                index += step;
            }
        }
        return res;
    }
};
// @lc code=end

```
