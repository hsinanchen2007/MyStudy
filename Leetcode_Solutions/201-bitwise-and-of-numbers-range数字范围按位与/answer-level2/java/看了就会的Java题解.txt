直接区间每个数与的话会超时，那么就要想办法给他降到常数级别，也就是只看m和n的位数来找到共同点。

其实假若**m和n的前x位完全一样**的话，那么中间的数即使变化也是在后面剩下那几位变化，也就是[m, n]区间的所有数**前x位都相同**，那么我们只要把m和n的类似**公共前缀位**找出来即为答案。
``` java
    public int rangeBitwiseAnd(int m, int n) {
   
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            
            int mask = 1 << i;
            // 找到最大数的起始位
            if (mask > n)
                continue;
            
            if ((mask & m) == (mask & n)) 
                res |= mask & m;
            else
                break;
        }

        return res;
    }
```
短点写的话就是楼上那些题解的方法了。