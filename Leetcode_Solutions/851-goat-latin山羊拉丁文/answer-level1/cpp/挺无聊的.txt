### 解题思路
执行用时 :0 ms, 在所有 cpp 提交中击败了100.00% 的用户
内存消耗 :9.1 MB, 在所有 cpp 提交中击败了81.52%的用户

从左到右扫描 遇到空格加后缀

### 代码

```cpp
class Solution {
public:
    string toGoatLatin(string S) {
        if (S.size() == 0) return S;
        char tb[] = {'a', 'e', 'i', 'o', 'u'};
        char f  = ' ';
        string rt;
        int d = 1;
        S += ' ';
        bool start = true;
        for(auto it : S)
        {
            if (it == ' ')
            {
                if (f != ' ')
                    rt += f;
                f = ' ';
                rt += "ma";
                for(int i = 0; i < d; i++)
                {
                    rt += 'a';
                }
                rt += ' ';
                d++;
                start = true;
            }
            else 
            {
                if (start)
                {
                    start = false;
                    char k = it >= 'A' && it <= 'Z' ? it - ('A' - 'a') : it;
                    if (find(tb, tb + 5, k) == tb + 5)
                    {
                        f = it;
                        continue;
                    }
                }

                rt += it;
            }
        }
        rt.resize(rt.size() - 1);
        return rt;
    }
};
```