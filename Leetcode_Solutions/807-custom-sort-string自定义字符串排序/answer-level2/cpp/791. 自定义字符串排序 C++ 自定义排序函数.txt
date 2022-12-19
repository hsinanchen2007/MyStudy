### 解题思路
自定义字符串排序函数
1）用全局变量把S的字符出现顺序保存下来
2）然后直接对T排序

### 代码

```cpp
unordered_map<char, int> indexmap;
class Solution {
public:
    static bool myfun(char a, char b)
    {
        if (indexmap.count(a) && indexmap.count(b)) {
            return indexmap[a] < indexmap[b];
        } else if (!indexmap.count(a)) {
            return false;
        } else if (!indexmap.count(b)) {
            return true;
        }

        return false;
    }
    string customSortString(string S, string T)
    {
        indexmap.clear();
        for (int i = 0; i < S.size(); i++) {
            indexmap[S[i]] = i;
        }

        sort(T.begin(), T.end(), myfun);

        return T;
    }
};
```