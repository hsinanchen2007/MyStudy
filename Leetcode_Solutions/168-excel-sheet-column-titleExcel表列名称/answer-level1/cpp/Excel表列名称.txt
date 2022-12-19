**本题实质就是10进制转化为26进制，但没有表示0的字母，需特别注意。**

```cpp
class Solution {
public:
    string convertToTitle(int n) {
        const char* alpha = "ZABCDEFGHIJKLMNOPQRSTUVWXY";
        string s;
        while(n > 0){
            int remainder = n % 26;
            s += alpha[remainder];
            n /= 26;
            if(remainder == 0)
                n--;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
```