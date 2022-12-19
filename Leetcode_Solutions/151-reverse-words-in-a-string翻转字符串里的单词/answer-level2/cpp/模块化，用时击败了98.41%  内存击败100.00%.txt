

```
class Solution {
public:
    //删除字符串从索引i开始到下一个单词之间的所有空格
    void delete_space(string &s, int i){    
        if(i >= s.length() || s[i] != ' ')  return;
        s.erase(s.begin() + i);
        delete_space(s, i);
    }

    //反转字符串从i到j的字符
    void reverse(string &s, int i, int j){  
        while(i < j)    swap(s[i++], s[j--]);
    }

    string reverseWords(string s) {
        delete_space(s, 0);             //删除开头的空格
        reverse(s, 0, s.length() - 1);  //反转整个字符串
        delete_space(s, 0);             //删除开头的空格
        int start = 0;
        int i = 0;
        while(i < s.length()){
            if(s[i] == ' '){
                //若发现空格，删除下一个位置到下一个单词之间的所有空格
                delete_space(s, i + 1);
                i++;
            }
            else{
                start = i;  //start保存单词开头, i找下一个空格
                while(s[i] != ' ' && i < s.length())  ++i;
                reverse(s, start, i - 1);  //反转这个单词
            }
        }
        return s;
    }
};
```
