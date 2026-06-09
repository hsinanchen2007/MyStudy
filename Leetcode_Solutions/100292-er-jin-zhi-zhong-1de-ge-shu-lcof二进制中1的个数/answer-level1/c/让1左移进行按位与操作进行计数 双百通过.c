
`1<<i`表示1左移i位，比如
    `1<<1`-->`10`
    `1<<2`-->`100`
    `1<<3`-->`1000`
让1与 uint32_t n 分别从低位到高位进行按位与，每与一次 就进行一次左移
每次为真时，count加1

```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        for(int i=0;i<32;i++){
            if(n&(1<<i)){
                count++;
            }
        }
        return count;
    }
};
```
