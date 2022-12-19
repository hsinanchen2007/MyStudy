### 解题思路
如果递归函数直接传子串代码会简单很多，但是会创建很多零碎的string，影响效率。

### 代码

```cpp
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size() || s1.size() == 0) return false;
        int len = s1.size();
        int msize = len * len * len;
        mark = new bool[msize];
        memset(mark, 0, sizeof(bool) * msize);
        res = new bool[msize];
        area = len * len;
        return match(s1, 0, s2, 0, len);
    }

    bool match(string& s1, int i1, string& s2, int i2, int len)
    {
        if (len == 1) return s1[i1] == s2[i2];
        int mpos = i1 * area + i2 * s1.size() + len - 1;
        if (mark[mpos]) return res[mpos];

        bool result = false;
        for (int i = i1 + 1; i < i1 + len; ++i)
        {
            int ll = i - i1;
            if (match(s1, i1, s2, i2, ll))
            {
                int rl = len - ll;
                if (match(s1, i, s2, i2 + ll, rl))
                {
                    result = true;
                    break;
                }
            }
            
            if (match(s1, i1, s2, i2 + len - ll, ll))
            {
                int rl = len - ll;
                if (match(s1, i, s2, i2, rl))
                {
                    result = true;
                    break;
                }
            }
        }

        mark[mpos] = true;
        res[mpos] = result;
        return result;
    }

    bool* mark;
    bool* res;
    int area;
};
```