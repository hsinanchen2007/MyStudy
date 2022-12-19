**注：大多数人容易忽略考虑末尾是空格的情况**
###  解法1：

```C++ []
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
        int pos=s.find_last_of(' ');//寻找到最后一个空格
        while(pos==s.length()-1)//将末尾的空格全部删除
        {
            if(s.empty()) return 0;
            s.erase(pos);
            pos=s.find_last_of(' ');
        }
        return s.length()-pos-1;
    }
};
```
注：此方法是边找最后一个空格并判断该空格是不是在末尾，是的话就继续清楚，否则停止。
###  解法 2：

```C++ []
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
        int size=s.size()-1;
        while(size>=0&&s[size]==' ')
        {
            s.erase(size);
            --size;
        }
        int pos=s.find_last_of(' ');
        return s.length()-pos-1;
    }
};
```
注：该方法是先将末尾的空格清除完后再找最后一个空格。

###  解法3：

```C++ []
class Solution {
public:
    int lengthOfLastWord(string s)
    {
        string word;
        stringstream ss(s);//字符串输入输出流自动过滤空格
        while(ss>>word){}//读取到最后一个单词
        return word.size();
    }
};
```
**觉得本文对你有帮助，点个赞噢谢谢**
