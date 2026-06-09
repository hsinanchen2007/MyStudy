class Solution {
public:
    string compressString(string S) {
        if(S.empty() || S.size() <= 1)  return S;
        string res;
        int i = 0, num = 0;
        while(i < S.size()){
            res += S[i];
            num = 1;
            while(i+1 < S.size() && S[i+1] == S[i]){
                i++;num++;
            }
            res += to_string(num);
            i++;
        }
        if(S.size() <= res.size())   res = S;
        return res;
    }
};