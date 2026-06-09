### 解题思路
用一个新的res数组(长度为max(a.length, b.length)+1)存放各位二进制加和结果。

### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        if(a=="0" && b=="0") return "0";
        if(a=="0" && b=="1" || a=="1" && b=="0") return "1";
        if(a=="1" && b=="1") return "10";
        int m = a.length(), n = b.length();
        int len = m>n ? m : n;
        if(m < n){
            for(int i=0; i<n-m; i++){
                a = "0" + a;
            }
        }
        if(m > n){
            for(int i=0; i<m-n; i++){
                b = "0" + b;
            }
        }
        string res = "";
        for(int i=len; i>=0; i--){
            res += '0';
        }
        for(int i=len; i>=1; i--){
            res[i] += (a[i-1]-'0') + (b[i-1]-'0');
            if(res[i]-'0' > 1){
                res[i] -= 2;
                res[i-1] += 1;
            }
        }
        if(res[0] == '0') return res.substr(1);
        return res;
    }
};

















```