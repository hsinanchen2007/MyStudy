![t1.jpg](https://pic.leetcode-cn.com/c22784b4905c2512dbd51da514dbd1a869c1db84af9a32b0f61d89f1161dc4ec-t1.jpg)
题意：判断一个字符串，只考虑字母数字（其它字符为干扰项），看是否为回文串。
一开始没注意到忽略大小写~还是要细心阅题呀
**解题步骤**
1. 去除原字符串的干扰项，并将字母统一大小写（大写/小写二选一） [需要遍历一次，字母和数字用isalnum()进行判断]
2. 得到所需判断的处理串[s1]（只含字母数字）
3. 由于回文正着看反着看都是一样的~这里偷个懒，用algorithm头文件里的std::reverse()直接将处理串反转
4. 看反转串(s2)和处理串(s1)是否相等就可以啦~
tips: string的"=="和"+="是重载运算符，意义分别为判断字符串内容是否相同 和 把字符/字符串增加到的运算符左边串的后方
```
class Solution {
public:
    bool isPalindrome(string s) {
        if (s == "")  return true;

        string s1, s2;
        int len{ static_cast<int>(s.length()) };
        for (int i = 0; i < len; i++)
        {
            if (isalnum(s[i]))
            {
                s1 += tolower(s[i]);
            }
        }
        s2 = s1;
        std::reverse(s1.begin(), s1.end());
        
        return s1 == s2;
    }
};
```

