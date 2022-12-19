```
class Solution {
public:
    int balancedStringSplit(string s) {
        int res=0;
        int temp=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L'){
                temp+=1;
            }
            else{
                temp-=1;
            }
            if(temp==0){
                res+=1;
            }
        }
        return res;
    }
};
```
