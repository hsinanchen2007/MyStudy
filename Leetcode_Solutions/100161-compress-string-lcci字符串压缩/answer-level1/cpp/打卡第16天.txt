遇到不同的字符就输出
```
class Solution {
public:
    string compressString(string S) {
        if(S.empty()) return S;
        string out = "";
        char tmp = S[0];
        int count = 1;
        for(int m=1;m<S.size();++m) {
            
           
            if(tmp != S[m]){
                out += tmp;
                out += to_string(count);
                tmp = S[m];
                count = 1;
            }else{
                count++;
            }
            
        }
              out += tmp;
                out += to_string(count);
        if(out.size()<S.size()) return out;
        return S;

    }
};
```
