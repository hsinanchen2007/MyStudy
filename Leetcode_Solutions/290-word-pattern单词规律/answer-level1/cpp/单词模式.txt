给定一种 pattern(模式) 和一个字符串 str ，判断 str 是否遵循相同的模式。

这里的遵循指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应模式。

示例1:

```
输入: pattern = "abba", str = "dog cat cat dog"
输出: true
```

示例 2:

```
输入:pattern = "abba", str = "dog cat cat fish"
输出: false
```

示例 3:

```
输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false
```

示例 4:

```
输入: pattern = "abba", str = "dog dog dog dog"
输出: false
```

首先要正确理解题目的意思，举例说明：
pattern = "abba", str = "dog cat cat dog"
意思是a->dog,b->cat,由于a！=b,所以dog也应该!=cat，满足返回true；
<hr>

##  解法1：
- 先将str中的单词读取出来到数组中
- 再利用哈希表map来建立键值对应关系，并对其进行判断(这里不能排除值相等的情况，如示例四的情况)
- 利用set集合排除相同元素的原理，将pattern的元素和单词载入set中，判断两者元素大小是否相等，若不存在值相等的情况，两者大小相等。
```
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> lis1;
        int pos;
        int i=0;
        while(pos!=-1)//读取str中的单词
        {
            pos=str.find_first_of(' ',i);
            string temp=str.substr(i,pos-i);
            lis1.push_back(temp);
            i=pos+1;
        }
        if(pattern.size()!=lis1.size()) return false;
        map<char,string> h;
        for(int i=0;i<lis1.size();i++)
        {
            if(h.count(pattern[i]))
            {
                if(h[pattern[i]]!=lis1[i])
                    return false;
            }
            else
            {
                h.insert(map<char,string>::value_type(pattern[i],lis1[i]));
            }
        }
        set<char> p(pattern.begin(),pattern.end());
        set<string> l(lis1.begin(),lis1.end());
        if(p.size()!=l.size())
            return false;
        return true;
    }
};
```

##  解法2：另一种读取单词的方式，其余不变

```
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> lis1;
        stringstream out(str);
        string word;
        while(out>>word)
            lis1.push_back(word);
        if(pattern.size()!=lis1.size()) return false;
        map<char,string> h;
        for(int i=0;i<lis1.size();i++)
        {
            if(h.count(pattern[i]))
            {
                if(h[pattern[i]]!=lis1[i])
                    return false;
            }
            else
            {
                h.insert(map<char,string>::value_type(pattern[i],lis1[i]));
            }
        }
        set<char> p(pattern.begin(),pattern.end());
        set<string> l(lis1.begin(),lis1.end());
        if(p.size()!=l.size())
            return false;
        return true;
    }
};
```

