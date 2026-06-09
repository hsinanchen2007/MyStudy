最低位判断+右移
```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            if(n&1) count++;
            n >>= 1;
        }
        return count;
    }
};
```
不过看题解发现用n&(n-1)将最低位1取反更快，不过都是`O(1)`的复杂度
