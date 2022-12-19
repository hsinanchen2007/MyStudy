比赛的时候用的脑瘫模拟写半天还有bug，这个方法清晰了很多。
```
class Solution {
public:
    string sortString(string s) {
        if (s.empty()) return s;
        vector<int> a(26,0);
        for(int i=0; i<s.length(); i++){
            a[int(s[i]-'a')]++;
        }
        string res = "";
        do{
            for(int i=0; i<26; i++){
                if(a[i]>0){
                    res = res + char(i+int('a'));
                    a[i]--;
                }
            }
            for(int i=25; i>=0; i--){
                if(a[i]>0){
                    res = res + char(i+int('a'));
                    a[i]--;
                }
            }
        }while(res.length()<s.length());
        return res;
    }
};
```
