```
class Solution {
public:
    int numDistinct(string s, string t) {
        int a = s.size(), b = t.size();
        if(!b || a < b){
           return !b? 1:0;
        }
        vector<long> m(a+1,0);
        for(int i = 0; i < b; ++i){
            long temp = m[i],q = -1;
            //temp为上一行的前一个值
            //q记录本行中上一次出现本字母的位置
            for(int j = i+1; j <= a; ++j){
                long p = m[j];
                if(i == 0){
                    if(s[j-1] == t[i]) m[j] = m[j-1]+1;
                    else m[j] = m[j-1];
                }
                else if(s[j-1] == t[i]){
                    if(q >= 0) m[j] = temp+m[q];
                    else m[j] = temp;
                    q = j;
                }
                else{//每行初始位不同时注意要置零
                    if(q > 0) m[j] = m[j-1];
                    else m[j] = 0;
                }
                temp = p;
            }
        }
        return m[a];
    }
};
```
