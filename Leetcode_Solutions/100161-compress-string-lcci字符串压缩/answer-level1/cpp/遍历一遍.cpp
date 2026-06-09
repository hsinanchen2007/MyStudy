记录**遍历位置**`i`及重复的字符**长度**`n`；
每压缩一遍，**比较***压缩后的字符串*是否小于*原字符串*，否则跳出循环，不再遍历

```
class Solution {
public:
    string compressString(string S) {
        int s_len = S.length();
        if(s_len < 3) return S;
        string com_s = "";
        com_s += S[0];
        int n = 1 , i = 0;
        while(true){
            i++;
            // cout<< "s[" << i-1 <<"] =" << S[i-1] <<endl;
            // cout<< "n = "<<n << endl;
            if(S[i-1] == S[i]){
                n++;
            }
            else{
                com_s += to_string(n) + S[i];
                n = 1;
                // cout<< com_s <<" "<< com_s.length()<<endl;
            }
            if(com_s.length() > s_len ) return S;
            if(i == s_len) break;
        }
        return com_s;

    }
};
```
