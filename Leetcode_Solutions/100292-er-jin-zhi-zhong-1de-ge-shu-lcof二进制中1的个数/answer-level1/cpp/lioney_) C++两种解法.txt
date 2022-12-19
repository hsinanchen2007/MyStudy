`方法一：`
```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n) {
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};
```
`方法二：`
```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n) {
            res++;
            // 将最后一个1变成0
            n &= (n-1);
        }
        return res;
    }
};
```

