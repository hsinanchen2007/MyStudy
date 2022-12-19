一开始直接用循环变量和字符串长度来计算返回的单词长度，发现尾部空格问题后引入一个单词长度计数，非空格才开始计数，长度不为0才允许返回。
```
class Solution {
public:
    int lengthOfLastWord(string s) {
            
        int i,len=0;
        for(i=s.length()-1;i>=0;i--){
            if(s[i]==' '){
                if(len != 0)
                    return len;
            }
            else{
                len++;
            }
        }
        return len;
    }
};
```
