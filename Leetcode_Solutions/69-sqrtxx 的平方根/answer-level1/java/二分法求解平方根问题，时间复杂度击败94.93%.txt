![xmysqrt.jpg](https://pic.leetcode-cn.com/518dd228c35034d3a92189d17570b0c7d692d361cec6ef2ab506d3522ca3cacc-xmysqrt.jpg)
上代码
```
public static int mySqrt(int x) {

        if (x == 0 || x == 1)
            return x;
        int left = 1;
        int right = x;
        int mid;
        while (left < right) {
            mid = (left + right) >>> 1;
            if (mid == x / mid) {
                return mid;
            }
            if (mid < x / mid) {
                left = mid + 1;
            }
            if (mid > x / mid) {
                right = mid;
            }
        }
        return left - 1;

    }
```

1:二分法理解很简单，细节问题很让人抓狂，特别是边界问题，如果控制不好容易死循环或者无解报错。
2:整型溢出问题，需要特别注意。在取平均值的时候和判断的时候，不要直接整型相加或者相乘，这种增益运算很容易溢出，需要
巧妙避免。
