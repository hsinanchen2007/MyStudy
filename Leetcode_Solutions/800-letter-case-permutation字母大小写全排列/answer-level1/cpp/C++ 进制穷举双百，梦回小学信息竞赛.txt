一个数组记录一下字母的位置，另外一个同样长度的数组进行01进制穷举，0表示不变，1表示大小写转换，因为长度小于12，所以不会爆。
```
class Solution {
public:
    void change(char& c){
        if(c>='a' && c<='z')
            c = (c-'a'+'A');
        else if(c>='A' && c<='Z')
            c = (c-'A'+'a');
    }
    vector<string> letterCasePermutation(string S) {
        vector<int> b(20,0);
        vector<int> a;
        vector<string> res;
        for(int i=0; i<S.length(); i++)
            if(isalpha(S[i])) a.push_back(i);
        while(true){
            string t = S;
            int c = 0;
            for(int i=0; i<a.size(); i++){
                if(b[i]) change(t[a[i]]);
                c += b[i];
            }
            res.push_back(t);
            if(c==a.size()) break;
            int p = a.size()-1;
            while(b[p]==1){
                b[p] = 0;
                p--;
            }
            b[p] = 1;
        }
        return res;
    }
};
```
