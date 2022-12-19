这个复杂度应该是O(n)吧
```
class Solution {
public:
    string tochar(int num){
        string res = "";
        while(num){
            res += num%10+'0';
            num /= 10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    string compressString(string s) {
        char c,pre='0';
        string res = "";
        int num = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]==pre) {
                num++;
            }
            else {
                pre = s[i];
                res+= tochar(num);
                num = 1;
                res += s[i];
            }
        }
        res+= tochar(num);
        return res.length()>=s.length()?s:res;
    }
};
```