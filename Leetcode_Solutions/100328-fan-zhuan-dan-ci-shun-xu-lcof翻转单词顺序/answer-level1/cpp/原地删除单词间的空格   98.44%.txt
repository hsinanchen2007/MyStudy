### 解题思路
![批注 2020-03-21 113207.png](https://pic.leetcode-cn.com/2d69126a1a42ae108b3c174ec9fedef7b7c36cc1f205cc3cf79014103544da2d-%E6%89%B9%E6%B3%A8%202020-03-21%20113207.png)


### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int begin = 0, end = 0;
        reverse(s.begin(), s.end());                //首先将整个字符串翻转
        s.erase(0, s.find_first_not_of(' '));       //删除该字符串头和尾部的空格
        s.erase(s.find_last_not_of(' ')+1);
        while(end <= s.size()){
            if(s[end] == ' ' || s[end] == '\0'){    //再逐个单词翻转回来
                reverse(s.begin()+begin, s.begin()+end);
                begin = end+1;
            }
            end++;
        }
        int i = 0, j = 0;
        while(j < s.size()){                        //原地删除单词间多余的空格
            while(j<s.size() && s[j] != ' ')    s[i++] = s[j++];
            while(j<s.size() && s[j] == ' ')    j++;
            if(j < s.size())    s[i++] = ' ';
            else    s[i] = '\0';
        }
        
        return s;
    }
};



```