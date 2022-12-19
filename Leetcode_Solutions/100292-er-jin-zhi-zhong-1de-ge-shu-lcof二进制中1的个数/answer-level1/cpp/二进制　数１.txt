将数与１进行＆操作，来判断每次最低位是否为１　来计算１个数
然后每次将将数的二进制右移１位
```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n!=0){
            if(n&1)ans++;
            n=n>>1;
        }
        return ans;
    }
};
```
