这个题思路好想的一个就是，我先遍历一遍字符串，把那些什么空格啥的全都不要，只保留数字字符和字母，存入一个新的字符串。 然后在判断这个新的字符串是不是回文串。 所谓回文，就是正着和反着一样。用双指针，一个往前，一个往后对比即可。

```cpp
class Solution {
public:
    bool isPalindrome(string s) {

        if (s.size()==0)
            return true;

        string s1="";

        for (int i=0; i<s.size(); i++)
        {
            if (isalnum(s[i]))
            {
                if (isupper(s[i]))
                    s[i] = tolower(s[i]);

                s1 += s[i];
            }
        }

        // 判断是不是回文字符串
        for (int i=0, j=s1.length()-1; i<=j; i++, j--)
        {
            if (s1[i] != s1[j])
                return false;
        }

        return true;
    }
};
```
上面可能比较好想，其实也个题也不用那么麻烦，只需要一次遍历即可，也是使用双指针，只不过，指针每一次找的时候，只招数字字符和字母，然后两个比较，移动。  上面的简化版。

```cpp
class Solution {
public:
    bool isPalindrome(string s) {

        if (s.size()==0)
            return true;

        cout << s << endl;

        int i=0;
        int j=s.size()-1;

        while(i<j)
        {
            while (i<j && !isalnum(s[i])) i++;
            while (i<j && !isalnum(s[j])) j--;

            if (tolower(s[i]) != tolower(s[j]))
                return false;

            i++;
            j--;

        }

        return true;
    }
};
```
这个题这是比较常规的思路了，主要是通过这个题整理C++的ctype库，有时候判断字符是不是整数或者字母，或者转换字母的大小写，这个库里面的函数比较好用。

关于一些知识补充和总结：C++ctype库和c++的各种输入，见我博客：
[https://blog.csdn.net/wuzhongqiang/article/details/103293457](https://blog.csdn.net/wuzhongqiang/article/details/103293457)