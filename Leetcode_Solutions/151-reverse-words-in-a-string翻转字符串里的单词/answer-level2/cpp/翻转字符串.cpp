### 解题思路
1. 首先要处理原字符串中多余的空格，将原字符串处理成一个类似这样的形式"word_word_word_"，
2. 然后对每个单词做翻转，因为每个单词翻转过程中要遍历到空格处，再记录单词的右边界，第一步中的末尾空格就是起这个作用
3. 第二步处理完后变成"drow_drow_drow_"，最后去除末尾空格，再对整体做一次翻转就可以了

### 代码

```cpp
class Solution {
public:
    void reverseWord(string& s, int left, int right){
        while(left < right){
            swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
    string reverseWords(string s) {
        string res = "";
        if(s == "") return res;
        int len = s.length();
        int i = 0;
        while(i < len){
            if(s[i] == ' '){
                i++;
            }else{
                res += s[i];
                i++;
                break;
            }
        }
        //去除都是空格的情况
        if(i == len && res == "") return res;
        //去除原字符串中多余空格
        while(i < len){
            if(s[i] == ' '){
                if(s[i-1] == ' '){
                    i++;
                }else if(s[i-1] != ' '){
                    res += ' ';
                    i++;
                }
            }else{
                res += s[i];
                i++;
            }
        }
        
        //先对每个单词单独翻转
        int mark = 0;//标记单词左边界
        int len2 = res.length();
        if(res[len2-1] != ' '){
            res += ' ';
            len2++;
        }
        for(int i = 0; i < len2; i++){
            if(res[i] == ' '){
                reverseWord(res, mark, i-1);
                mark = i + 1;
            }
        }
        //对整体做翻转，注意res末尾实际上有一个空格，需要去掉
        res = res.substr(0,len2-1);//去除末尾空格
        reverseWord(res, 0, len2-2);
        return res;
    }
};
```