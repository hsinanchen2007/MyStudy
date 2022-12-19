### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string toGoatLatin(string S) {
        int b=0;
        int count=0;
        string ans;
        for(int i=0;i<S.length();i++){
            if(S[i]==' '||i==S.length()-1){
                if(i==S.length()-1){
                    i++;
                }
                string t=S.substr(b,i-b);
                if(t[0]=='a'||t[0]=='e'||t[0]=='i'||t[0]=='o'||t[0]=='u'||t[0]=='A'||t[0]=='E'||t[0]=='I'||t[0]=='O'||t[0]=='U'){
                    ans+=t;
                    ans+="ma";
                }
                else{
                    ans+=t.substr(1,t.length()-1);
                    ans+=t[0];
                    ans+="ma";
                }
                count++;
                int d=count;
                while(d--){
                    ans+='a';
                }
                if(i!=S.length()){
                    ans+=' ';
                }
                b=i+1;
            }
        }
        return ans;
    }
};
```