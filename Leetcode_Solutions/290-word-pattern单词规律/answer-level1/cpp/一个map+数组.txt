### 解题思路
map存储string对应的char，bool数组存储已经访问过的字符。
* 遍历整个str，空格分隔开各个word，为了方便处理在后面添加个空格' ';
* 若当前字符为空格' '，则已经输入了一个字符串word了，反之则添加到word里；
* 获取到一个word后：
    * 先检查是否还有pattern对应，若pattern已经没有多余的字符，则返回false；
    * 然后再检查map中是否有word对应的字符；
        * 若有，则检查是否对应pattern里的字符，不对应则返回false；
        * 若不存在且对应的字符是否已经使用，使用了则返回false，若未使用则添加到map里；
* 检查pattern是否全都对应完了


### 代码

```cpp
class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        map<string, char> m;
        bool used[128] = {false};
        string word;
        str.push_back(' ');
        int idx = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != ' ')
            {
                word.push_back(str[i]);
            }
            else
            {
                if (idx == pattern.size())
                    return false;
                if (m.count(word))
                {
                    if (m[word] != pattern[idx])
                        return false;
                }
                else
                {
                    if (used[pattern[idx]])
                        return false;
                    else
                    {
                        m[word] = pattern[idx];
                        used[pattern[idx]] = true;
                    }
                }
                word.clear();
                idx++;
            }
        }
        return idx == pattern.size();
    }
};
```

![图片.png](https://pic.leetcode-cn.com/f0849c98bc720a371a8bdcb925c3cdbef698bc9b2bd3dd2c8d38b16825ab1250-%E5%9B%BE%E7%89%87.png)
