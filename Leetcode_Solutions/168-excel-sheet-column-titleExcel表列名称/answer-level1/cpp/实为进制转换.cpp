将1-26转换为A-Z的26进制表示。利用一个数组存储每个字母，然后对数字n求余转换为字母，再将n除以26处理高位，依次类推，直至n为0.
```
class Solution {
public:
    string convertToTitle(int n) {
        char alpha[26];
        for(int i=0;i<26;++i)
            alpha[i]='A'+i;
        
        string s;
        int res;
        while(n)
        {
            res=(n-1)%26;
            s=alpha[res]+s;
            n=(n-1)/26;
        }
        return s;
    }
};
```
