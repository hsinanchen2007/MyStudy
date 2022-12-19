![image.png](https://pic.leetcode-cn.com/e179925324ad949f845a999c1705c0cc79d101d020657592b66d6373ae454e8b-image.png)

就是位运算比较占内存。。
```
class Solution {
    public boolean isPowerOfTwo(int n) {
        if (n == 0)return false;
        if (n == 1)return true;
        if (n%2==1)return false;
        while(n%2==0){
            n = n>>1;
        }
        return n==1;
    }
}
```
