不用递归，完全按照人的思维方式进行解题
```
class Solution {
public:
    string countAndSay(int n) {
        string s1 = "1",s2 = "";
        char itoa;
        if(n==1){return s1;}
        for(int i = 1;i < n;i++){
            int count = 0;
            int len = s1.size();
            char c = s1[0];
            for(int j = 0;j < len;j++){
                if(s1[j]==c){
                    count++;
                }
                else{
                    itoa = count + '0';
                    s2 += itoa;
                    s2 += c;
                    c = s1[j];
                    count = 1;
                }
                if(j==len-1){
                    itoa = count + '0';
                    s2 += itoa;
                    s2 += c;
                }
            }
            s1 = s2;
            s2 = "";
        }
        return s1;
    }
};
```
