不能用+、-符号，第一反应是位运算，但是并没有想到异或和与的结合，而是按部就班的计算。。。
将每个数从低位到高位计算，因为是int，考虑到负数，循环32次得到结果。
```
class Solution {
public:
    int getSum(int a, int b) {
        int i = 1, ret = 0;
        bool up = false;
        while (i > 0 || i == 1<<31) {;
            if (i & a && i & b) {
                up = true;
            } else if (i & a || i & b) {
                if (ret & i) {
                    up = true;
                    ret &= (~i);//将当前位的1变为0
                }
                else
                    ret |= i;
            }
            if (i == 1<<31) break;
            if (up) ret |= (i << 1);
            i <<= 1;
            up = false;
        }
        return ret;
    }
};
```

主流解法
```
class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, ((unsigned int)a & b) << 1);
    }
};
```
