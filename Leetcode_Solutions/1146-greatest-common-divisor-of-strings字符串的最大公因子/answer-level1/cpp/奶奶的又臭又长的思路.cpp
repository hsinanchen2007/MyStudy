奶奶的又臭又长的思路
```


class Solution {
public:
    inline int gcd(int a,int b) {
        if(a%b==0) return b;
            else return (gcd(b,a%b));
    }
    string gcdOfStrings(string str1, string str2) {
        // 最大公约数。
        
        // 字符串str1的最大公约a ， 字符串str2的最大公约b
        // 如果b 是 a 的最大公约 则返回b。
        string suba = str1;
        for(int step=1;step<=str1.length();step++){
            string sub = str1.substr(0,step);
            int j=step;
           // cout<<sub<<" ";
            for(;j<str1.length();j+=step){
               if(sub.compare(str1.substr(j,step)) != 0){
                   break;
               } 
            }
            //cout<<j<<endl;
            if(j >=str1.length()){
                suba = sub;
                break;
            }
        }
        //cout<<suba<<endl;

        string subb = str2;
        for(int step=1;step<=str2.length();step++){
            string sub = str2.substr(0,step);
            int j=step;
            for(;j<str2.length();j+=step){
               if(sub.compare(str2.substr(j,step)) != 0){
                   break;
               } 
            }
            if(j >=str2.length()){
                subb = sub;
                break;
            }
        }
        if(subb.find(suba) == subb.npos) 
            return "";
        else{
            string ans = "";
            int lc = str1.length() / subb.length();
            int rc = str2.length() / subb.length();

            int gcdans = gcd(lc,rc);
            while(gcdans--) ans += subb;

            return ans;
        }
            
        

        
    }
};
```
