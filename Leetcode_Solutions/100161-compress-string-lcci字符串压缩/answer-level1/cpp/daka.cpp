```
class Solution {
public:
    string compressString(string S) {
        if(S == "")
            return "";
        
        char ch = S[0];
        int counter = 0;
        string rec = "";
        
        for(int i = 0; i < S.size(); i++){
            if(ch == S[i])
                counter++;
            else{
                rec += ch + to_string(counter);
                if(rec.size() >= S.size())
                    return S;
                ch = S[i];
                counter = 1;
            }
        }
        rec += ch + to_string(counter);
        return rec.size() < S.size()? rec: S;
    }
};
```
