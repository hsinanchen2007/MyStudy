大佬们暴力打表实属牛逼，C++递归祭出
```
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string res = "", tmp = countAndSay(n-1);
        int count = 0;
        char a = tmp[0];
        for(int i=0; i<tmp.size(); i++){
            if(tmp[i] == a) count++;
            else{
                res += to_string(count);
                res += tmp[i-1];
                a = tmp[i];
                count = 1;
            }
        }
        res += to_string(count);
        res += tmp.back();
        return res;
    }
};
```
