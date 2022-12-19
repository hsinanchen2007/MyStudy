```
typedef long long ll;
class Solution {
public:
    int myAtoi(string s) {
        ll res=0;
        int n=s.length();
        int i=0;
        int bol=1;
        while(i<n&&s[i]==' ')i++;
        if(s[i]=='-'){
            bol=-1;
            i++;
        }else if(s[i]=='+')i++;
        else if(s[i]>'9'||s[i]<'0')return 0;
        for(int j=i;j<n;j++){
            if(s[j]>'9'||s[j]<'0')break;
            else{
                res=res*10+s[j]-'0';
                if(res>INT_MAX){
                    if(bol==-1){
                        res=(ll)-1*(INT_MIN);
                    }else{
                        res=INT_MAX;
                    }
                    break;
                }
            }
        }
        return res*bol;
    }
};
```