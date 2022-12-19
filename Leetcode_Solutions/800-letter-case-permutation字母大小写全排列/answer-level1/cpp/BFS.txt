```c++
class Solution {
public:
    bool isAlpha(char c){
        if ((c>='a' && c<='z') || (c>='A' && c<='Z'))
            return true;
        return false;
    }
    char transAlpha(char c){
        if ((c>='a' && c<='z'))
            return c-'a'+'A';
        return c-'A'+'a';
    }

    vector<string> letterCasePermutation(string S) {
        vector<string> res={""};
        for (char c:S){
            int size=res.size();
            if (!isAlpha(c)){
                for (int t=0;t<size;t++)
                    res[t]+=c;
            }
            else{
                vector<string> mes;
                for (int t=0;t<size;t++){
                    mes.push_back(res[t]+c);
                    mes.push_back(res[t]+transAlpha(c));
                }
                res.assign(mes.begin(),mes.end());
            }
        }
        return res;
    }
};
```
