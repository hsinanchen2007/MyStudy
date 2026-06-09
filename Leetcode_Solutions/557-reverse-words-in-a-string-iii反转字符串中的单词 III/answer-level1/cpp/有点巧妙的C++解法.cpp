```
class Solution {
public:
    string reverseWords(string s) {
        int pos=0;
        int left=0,right=0;
        s.push_back(' ');
        int len=s.length();
        while(pos<len){
            if(s[pos]==' '){
                right=pos-1;
                while(left<right){
                    swap(s[left], s[right]);
                    ++left;
                    --right;
                }    
                left=pos+1;
            }
            ++pos;
        }
        s.erase(s.end()-1);
        return s;
    }
};
```
思路很简单，按照空格切分，然后逆转每个单词
但是有个值得注意的地方，直接使用原字符串的话，首末单词判定的时候会出现特殊情况
比如，如果按照单词后的空格作为切分标志，最后一个单词是特殊情况，末尾没有空格
如果按照单词前面的空格作为切分标志，首单词前没有空格
所以，这里思路很简单，先给原字符串末尾加一个空格，这样就能够统一处理所有单词
按照单词尾部的空格为标志，逆转所有单词
完事儿之后还要记得把字符串末尾的空格删掉
代码还能写得更简洁，把自增自减运算符放在运算里面，然后去掉大括号
但是这样会导致可读性变差
所以代码就这样了，简单易懂