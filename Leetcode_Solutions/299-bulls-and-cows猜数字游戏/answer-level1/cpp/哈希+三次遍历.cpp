```
class Solution {
public:
    string getHint(string secret, string guess) {
        if(secret.length()==0)return secret;
        int cnt[10];
        memset(cnt,0,sizeof(cnt));
        int a=0,b=0;
        
        for(int i=0;i<secret.length();i++){
            cnt[secret[i]-'0']++;
        }

        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]){cnt[secret[i]-'0']--;a++;}
        }

        for(int i=0;i<secret.length();i++){
            if(secret[i]!=guess[i]&&cnt[guess[i]-'0']>0){b++;cnt[guess[i]-'0']--;}
        }      
string  s;
s+=to_string(a);
s+='A';
s+=to_string(b);
s+='B';
return s;
    }
};
```
