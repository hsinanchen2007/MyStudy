先对字符串进行整体翻转，再对翻转后的字符串中的每一字符单独进行翻转。
"  hello world!  " -> " world! hello "
对删除连续两次出现空格的其中一个字符，再检查首尾是否为空格。
```
class Solution {
public:
    void reverse(string &s, int start , int end)
    {
        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }


    string reverseWords(string s) {
        if (s=="")
        {
            return s;
        }
        int start = 0; 
        int end = s.length();

        reverse(s, start, end-1);

        bool isstart = false;

        for(int i = 0; i < s.length(); i++)
        {
            if (!isstart && s[i] != ' ')
            {
                isstart = true;
                start = i;
                continue;
            }
            if(isstart && s[i] == ' ')
            {
                reverse(s, start, i-1);
                isstart = false;
            }
        }
        if (isstart)
        {
            reverse(s, start, end-1);
        }

        for(int i = 0; i < s.length()-1; )
        {
            if(s[i] == ' ' && s[i+1] == ' ')
            {
                s.erase(s.begin() + i);
                continue;
            }
            i++;
        }

        if(s != "" && s[0] == ' ')
        {
            s.erase(s.begin());
        }
        if(s != "" && s[s.length()-1] == ' ')
        {
            s.erase(s.begin() + s.length()-1);
        }
        return s;
    }
};
```
