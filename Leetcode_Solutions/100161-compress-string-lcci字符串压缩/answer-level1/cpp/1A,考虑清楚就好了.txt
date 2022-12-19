```
class Solution {
public:
    string compressString(string S) {
        string S2 = "";
        string tmp = "";
        int cnt = 0;
        for(int i=0;i<=S.length();i++){
            if(i == 0 ||i == S.length() || S[i-1] != S[i]){
                if(i != 0){
                     S2 += tmp + to_string(cnt);
                }  
                tmp = S[i];cnt=1;
            }else{
                cnt++;
            }
        }
        if (S2.length() < S.length()) return S2;
        return S;
    }
};
```
