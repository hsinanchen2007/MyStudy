### 解题思路
![image.png](https://pic.leetcode-cn.com/77c36dfb18fd063aab39d7107bf2f9039beae5c2838e613e8d3d12cc500b8919-image.png)

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)return s;
        string ress = "";
        int gap = numRows * 2 - 2;
        int st = 0;
        for(int i = 0; i < numRows; i++)
        {
            st = i;
            while(st < s.size())
            {
                ress += s[st];
                if(st % gap != 0 && st % gap != gap / 2 
                        && st + gap - 2 * i < s.size())
                {
                    ress += s[st + gap - 2 * i];
                }
                st += gap;
            }
        }
        return ress;
    }
};
```