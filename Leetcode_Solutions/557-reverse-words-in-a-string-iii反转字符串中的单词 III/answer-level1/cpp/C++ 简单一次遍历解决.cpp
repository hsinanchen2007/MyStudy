```
class Solution {
public:
    string reverseWords(string s) {
        int pos=0;
        for(int i=0;i<s.size();++i){
            if(s[i]==' '){//找到空格就将与前一个空格之间的字符串反转
                reverse(s.begin()+pos,s.begin()+i);
                pos=i+1;//更改前一个空格位置
            }
        }  
        reverse(s.begin()+pos,s.end()); //最后结尾的一个单词需要反转
        return s;
    }
};
```
