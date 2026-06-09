```
class Solution {
public:
    string sortString(string s) {
        string res;
        vector<int> aphlabet(26,0);
        for(char x:s)
            aphlabet[x-97]++;
        while(true){
            int new_add = 0;
            for(int i=0;i<26;i++){
                if(aphlabet[i]>0){
                    res+=i+97;
                    aphlabet[i]--;
                    new_add++;
                }
            }
            for(int i=25;i>-1;i--){
                if(aphlabet[i]>0){
                    res+=i+97;
                    aphlabet[i]--;
                    new_add++;
                }
            }
            if(new_add==0)
                break;
        }
        return res;
    }
};
```
