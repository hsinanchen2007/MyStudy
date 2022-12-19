#  反转字符串中的元音字母
编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1:

```
输入: "hello"
输出: "holle"
```
示例 2:

```
输入: "leetcode"
输出: "leotcede"
```
说明:
元音字母不包含字母"y"。

<hr>

##  分析：
- 是将单词中的元音序列反转
- 元音包括a，e，i，o，u，A，E，I，O，U


##  解法1：双指针法，利用set判断是否是元音字符

```
class Solution {
public:
    string reverseVowels(string s) {
        set<char> a;
        a.insert('a');
        a.insert('e');
        a.insert('i');
        a.insert('o');
        a.insert('u');
        a.insert('A');
        a.insert('E');
        a.insert('I');
        a.insert('O');
        a.insert('U');
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            while(!(a.find(s[i])!=a.end())&&i<j)
                i++;
            while(!(a.find(s[j])!=a.end())&&i<j)
                j--;
            swap(s[i++],s[j--]);
        }
        return s;
    }
};
```

##  解法2：更改了查找元音字符的查找方式

```
class Solution {
public:
    bool find(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
        ||c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            while(!find(s[i])&&i<j)
                i++;
            while(!find(s[j])&&i<j)
                j--;
            swap(s[i++],s[j--]);
        }
        return s;
    }
};
```

