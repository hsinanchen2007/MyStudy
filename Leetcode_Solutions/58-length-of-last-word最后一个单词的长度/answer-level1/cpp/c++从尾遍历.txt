```
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
       
        bool word=0;                   //是否为字母
        char c=' ';
        int res=0;
        for( auto iter=s.end()-1;;iter--){         //从最后一个字母开始循环
            if(*iter!=c) {                         //不是空格
                res++;
                word=1;
            }
            if(iter==s.begin()) return res;        //是第一个位置（可能是字母或空格）
            if(*iter==c&&word) return res;         //是单词间的空格 
        }
        return 0;
    }
};
```
