### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string getHint(string secret, string guess) {
        int buf1[10]={0};
        int buf2[10]={0};
        int A=0,B=0;
        for(int i=0;i<guess.size();i++){
            if(secret[i]==guess[i]){
                A++;
            }
            else{
                int t=secret[i]-'0';
                buf1[t]++;
                buf2[guess[i]-'0']++;
            }
        }
        for(int i=0;i<=9;i++){
            while(buf1[i]&&buf2[i]){
                B++;
                buf1[i]--;
                buf2[i]--;
            }
        }
        string s=to_string(A);
        s+='A';
        s+=to_string(B);
        s+='B';
        return s;
    }
};
```