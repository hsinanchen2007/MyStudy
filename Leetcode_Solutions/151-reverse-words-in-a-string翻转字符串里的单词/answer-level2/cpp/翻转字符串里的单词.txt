### 算法分析
1. 假设tmp表示当前待添加的单词, res表示结果字符串
2. 从尾遍历字符串s, i = s.size() - 1 : 0
3. if s[i] != '' then tmp = s[i] + tmp
4. if s[i] == ' ' && !tmp.empty() then res += ' ' + tmp
5. if s[i] != ' ' && i == 0 then res += ' ' + tmp
6. return res
### 复杂度分析
+ 时间复杂度：O(n), n=s.size()
+ 空间复杂度：O(m), m = max(tmp.size())
### 源码
```C++ []
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty())
            return "";
        
        string res = "";
        string tmp = "";

        for (int i = s.size() - 1; i >= 0; i--)
        {
            bool addTmp = false;

            if (s[i] == ' ')
            {
                if (!tmp.empty())
                {
                    addTmp = true;
                }
            }
            else
            {
                tmp = s[i] + tmp;

                if (i == 0)
                {
                    addTmp = true;
                }
            }

            if (addTmp)
            {
                if (!res.empty())
                    res += ' ';
                res += tmp;
                tmp = "";
            }
        }

        return res;
    }
};