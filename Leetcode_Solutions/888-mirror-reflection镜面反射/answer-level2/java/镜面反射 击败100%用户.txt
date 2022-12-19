假设上边镜面不存在 每次经过上面镜面则上下位置镜像翻转一次。

kp = mq 时 则终止了 ，翻了奇数次 左右偶数次 则是2号，翻了奇数次 左右奇数次 则是0号。则有：

```
private int mirrorReflections(int p, int q) {
        int k = 1, m = k * p / q;
        while (k * p % q != 0) {
            k++;
            m = k * p / q;
        }
        //翻了奇数次 左右偶数次 则是2号
        if (k % 2 == 1 && m % 2 == 0) {
            return 2;
        }
        //翻了奇数次 左右奇数次 则是0号
        if (k % 2 == 1 && m % 2 == 1) {
            return 1;
        }
        return 0;
    }
```
