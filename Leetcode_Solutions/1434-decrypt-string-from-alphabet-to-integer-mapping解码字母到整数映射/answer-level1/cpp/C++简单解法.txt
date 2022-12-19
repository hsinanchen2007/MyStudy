
```
class Solution {
public:
    string freqAlphabets(string s) {
        //首先判断(i+2 < len && s[i+2] == '#')，如果是，则为xx#类型，进行特殊处理
        //否则直接使res += 'a' + s[i] - '1';
        string res;
        int len = s.size();
        for(int i = 0; i < len; i++){
            if(i+2 < len && s[i+2] == '#'){
                int num = s[i] - '0';
                num *= 10;
                num += s[i+1] - '0';
                res += 'a' + num - 1;
                i += 2;
            }else res += 'a' + s[i] - '1';
        }
        return res;
    }
};
```
