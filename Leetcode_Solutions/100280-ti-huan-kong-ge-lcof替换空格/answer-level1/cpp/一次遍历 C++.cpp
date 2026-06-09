遍历string，非空格原样插入，遇到空格替换成"%20"插入
```
class Solution {
public:
    string replaceSpace(string s) {
        if(s.empty()) return s;
        string res;
        for(char a:s){ //遍历
            if(a != ' ') res += a; //非空格字符直接插入
            else res += "%20"; //空格替换为"%20"插入
        }
        return res;
    }
};
```
