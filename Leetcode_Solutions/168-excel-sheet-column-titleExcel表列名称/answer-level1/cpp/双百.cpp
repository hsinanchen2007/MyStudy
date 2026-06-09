### 解题思路
稍微处理一下n是26倍数的情况

### 代码

```cpp
class Solution {
public:
    string convertToTitle(int n) {
        int k=1;
        for(long i=0;i<n;){
            i=i+pow(26,k);
            k++;
        }//计算位数
        string s(k-1,0);
        for(int i=k-2;i>=0;--i){
            s[i]=n%26+64;
            if(s[i]==64) s[i]=90,n--;//Z
            n/=26;
        }
        return s;
    }
};
```