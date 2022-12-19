![image.png](https://pic.leetcode-cn.com/25003ca4f9969d303c331220a46c024e12e7ec82819a9b9dd4c0e6c6b7a1ba4d-image.png)
解题思路：n = n&(n-1),使n的最低位1清除，计算‘&’操作的次数即可。
```
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n != 0){
            n &= n-1;
            ++res;
        }
        return res;
    }
```

