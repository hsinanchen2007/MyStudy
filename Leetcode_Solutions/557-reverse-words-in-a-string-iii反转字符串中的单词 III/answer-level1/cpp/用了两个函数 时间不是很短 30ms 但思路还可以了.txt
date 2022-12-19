### 解题思路
split是珍藏多年的

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s)
    {
        if (s == "") return "";
        vector<string> word = split(s, ' ');
        int num = word.size();
        for (int i = 0; i < num; i++)
            word[i] = myReverse(word[i]);
        string res = "";
        for (int i = 0; i < num - 1; i++)
            res += word[i], res.push_back(' ');
        res += word[num - 1];
        return res;
    }
    vector<string> split(string str, char ch) //再次搬出了我珍藏的自创split
    {
        vector<string> subs;
        for (int i = -1, k = 0; k < str.length(); )
        {
            while (str[k] == ch) k++;
            i++;
            subs.push_back("");
            while (str[k] != ch && k < str.length())
            {
                subs[i] += str[k];
                k++;
            }
            if (subs[i] == "") subs.pop_back();
        }
        return subs;
    }
    string myReverse(string str) //翻转字符串
    {
        char tmp;
        int len = str.length();
        for (int i = 0; i < len / 2; i++)
            tmp = str[i], str[i] = str[len - 1 - i], str[len - 1 - i] = tmp;
        return str;
    }
};
```