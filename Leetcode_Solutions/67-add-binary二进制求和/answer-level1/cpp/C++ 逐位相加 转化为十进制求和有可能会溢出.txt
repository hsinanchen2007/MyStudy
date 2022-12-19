```
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int len=min(a.length(),b.length());
        int ad=0;
        string result;
        for(int i=0;i<len;++i){
            int sum=ad+a[i]-'0'+b[i]-'0';
            ad=sum/2;
            result+=to_string(sum%2);
        }
        if(a.length()==len){
            for(int i=len;i<b.length();++i){
                int sum=ad+b[i]-'0';
                ad=sum/2;
                result+=to_string(sum%2);
            }
        }else{
            for(int i=len;i<a.length();++i){
                int sum=ad+a[i]-'0';
                ad=sum/2;
                result+=to_string(sum%2);
            }
        }
        if(ad==1) result+=to_string(ad);
        reverse(result.begin(),result.end());
        return result;
    }
};
```
