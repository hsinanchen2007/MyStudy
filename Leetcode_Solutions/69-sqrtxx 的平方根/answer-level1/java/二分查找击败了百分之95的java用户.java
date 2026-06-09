看了参考题解，牛顿法什么的。感觉作为一个算法题还是不应该牵涉到太多的数学知识。
本题的考察点主要是二分查找。
还有一点需要注意的是，x*x<y为了防止x*x越界。可以用long来处理。但是long会占用更多的内存。
此处用了点小技巧，写成x<y/x具体见代码。
更多二分查找相关的题解[点击此处](https://blog.csdn.net/reed1991/article/details/53341385)
```
public int mySqrt(int x) {
        if (x == 1 || x == 0) {
            return x;
        }
        int start = 1;
        int end = x / 2 + 1;
        int mid = 0;
        while (start <= end) {
            mid = start + (end - start) / 2;
            //防止越界
            if (mid <= x / mid && (mid + 1) > x / (mid + 1)) {
                return mid;
            }
            if (mid > x / mid) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return mid;
    }
```
