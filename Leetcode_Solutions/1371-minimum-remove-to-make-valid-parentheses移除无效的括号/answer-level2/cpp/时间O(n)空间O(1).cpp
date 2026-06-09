第一次从前向后遍历删除非法的')'
第二次从后向前遍历删除多余的'('
```
class Solution {
public:
    string minRemoveToMakeValid(string &s) {
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') cnt++;
            else if(s[i]==')'){
                if(cnt) cnt--;
                else{
                    s.erase(s.begin()+i,s.begin()+i+1);
                    i--;
                }
            }
        }
        if(cnt<=0) return s;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='('&&cnt){
                s.erase(s.begin()+i,s.begin()+i+1);
                --cnt;
            }
        }
        return s;
    }
};
```

