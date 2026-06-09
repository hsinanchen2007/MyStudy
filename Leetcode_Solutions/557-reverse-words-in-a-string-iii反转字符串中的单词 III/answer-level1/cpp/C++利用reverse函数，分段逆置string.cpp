主要思路就是先将第一个单词单独的找到并且逆置，因为后面的每个单词两边都有空格作为依据，只有第一个单词不是（最后一个单词因为有string.end()，所以也可以放到一起处理）。后面的单词都放到一个while循环中去依照两个空格之间是一个单词，调用一次reverse函数这样的方法处理，最后的用时和内存消耗还可以。
执行用时 :24 ms, 在所有 C++ 提交中击败了81.65%的用户
内存消耗 :11.6 MB, 在所有 C++ 提交中击败了95.63%的用户
```
class Solution {
public:
    string reverseWords(string s) 
    {
        auto i=s.begin();
        for(;i!=s.end();i++)
        {
            if(*i==' ') break;
        }
        reverse(s.begin(),i);
        auto j=i+1;
        while(j<=s.end())
        {
            if(*j==' ')
            {
                reverse(i+1,j);
                i=j;
            }
            if(j==s.end())
            {
                reverse(i+1,j);
                break;
            }
            j++;
        }
        return s;
    }
};
```
