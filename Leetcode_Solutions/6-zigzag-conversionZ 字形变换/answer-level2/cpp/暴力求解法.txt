### 解题思路
直接观察随着numRows的变化排列结构的变化，发现其中规律，然后直接暴力遍历即可（用时居然还可以）。
![捕获.PNG](https://pic.leetcode-cn.com/eddebbac02715a21a9b8fc57d78097053f4e89c7593e609e1bc7d99735cef871-%E6%8D%95%E8%8E%B7.PNG)


### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        if(numRows == 1)return s;
        int group = 2 * numRows - 2;
        for(int i = 0; i < numRows; i++)
        {
            int pos = i;
            while(pos < s.size())
            {
                res += s[pos];
                int base = group - 2 * i;
                if(base > 0 && base < group && pos + base < s.size())
                    res += s[pos + base];
                pos = pos + group;
            }
        }
        return res;
    }
};
```