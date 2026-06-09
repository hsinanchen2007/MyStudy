思路还是一样的遇到3 4 7就玩完
所有数位上的数存在2 5 6 9之一即可
转成字符串操作

```
class Solution {
public:
    int rotatedDigits(int N) {
        int count=0;
        for (int i=1;i<=N;i++){
            bool flag=false;
            string s = to_string(i);
            for(int j=0;j<s.size();j++){
                if(s[j]=='3'||s[j]=='4'||s[j]=='7') {flag=false;break;}
                if(s[j]=='2'||s[j]=='5'||s[j]=='6'||s[j]=='9') flag=true;
            }
            if (flag==true) count++;
        }
        return count;
    }
};
```