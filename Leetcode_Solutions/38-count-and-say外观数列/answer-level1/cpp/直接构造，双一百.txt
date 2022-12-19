### 解题思路
没打表，双一百，无情。
![image.png](https://pic.leetcode-cn.com/1a4d849e65b9998aaee99bb7da91cc35aaf3d2966b925ab7ed20d0635393038c-image.png)


### 代码

```cpp
class Solution {
    string getS(string str)
    {
        string res;
        int count = str.size();
        for(int i = 0; i < count;++i)
        {
            int num = 1;
            while((i + 1) < count && str[i] == str[i + 1])
            {
                ++num;
                ++i;
            }
            res += (string(1, num + '0') + string(1, str[i]));
        }
        return res;
    }
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 1; i < n; ++i)
        {
            res = getS(res);
        }
        return res;
    }
};
```