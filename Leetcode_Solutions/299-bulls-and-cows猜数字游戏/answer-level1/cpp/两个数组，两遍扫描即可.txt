
0ms

```c++
class Solution {
public:
    string getHint(string secret, string guess) {
        int A=0,B=0;
        int m1[10]{0},m2[10]{0};
        for(int i=0;i<secret.size();i++){
            if(secret[i] == guess[i]){
                A++;
            }else{
                m1[secret[i]-'0']++;
                m2[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            B+= min(m1[i],m2[i]);
        }
        char out[100];
        sprintf(out,"%dA%dB", A,B);
        return string(out);
    }
};
```