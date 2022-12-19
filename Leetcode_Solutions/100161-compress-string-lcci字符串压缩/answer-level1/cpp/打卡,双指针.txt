```
class Solution {
public:
    string compressString(string S) {
        string res="";
        int slow=0,fast=1;

        while(fast<S.size()){
            if(S[fast]==S[slow])
            {
                fast++;
            }
            else{
                res+=S[slow]+to_string(fast-slow);
                slow=fast,fast++;
            }
        }
        res+=S[slow]+to_string(fast-slow);
        if(res.size()>=S.size()) return S;
        else return res;
    }
};
```
