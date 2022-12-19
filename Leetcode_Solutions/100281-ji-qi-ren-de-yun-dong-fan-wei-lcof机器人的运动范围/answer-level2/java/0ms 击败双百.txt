# 题解
**注：图片可以在新标签页中打开放大。**
1.在m行n列的方格里面移动，即在一个坐标系里面，满足x∈[0, m - 1],y∈[0, n-1]。
2.坐标的数位之和小于等于k，分两种情况 0 <= k < 9 和 9 <= k <= 20。为啥分这两种：
1） 当 0 <= k < 9 时，只需要考虑个位的大小，它只存在一条屏障线（ y = -x + k ），如下图中 k = 8 的线条（深红色）所示。坐标不可能越过这条线。
2）当 9 <= k <= 20 时：
① 就拿 k = 9 来说，它存在两条屏障线（ y = -x + 9, y = -x +18），如下图中 k = 9 的线条（浅红色）所示。怎么看待这两条屏障线呢？用斜线的角度进行分区间操作，一、当x∈[0, 9]且y∈[0, 9]时，得用 x + y <= 9 来衡量；二、当x∈[10, 19]且y∈[0,9]，或者x∈[0, 9]且y∈[10, 19]时，得用 x + y <= 18来衡量。用java来表示就是

```java []

int answer = 0;
for (int x = 0; x < m; x++) {
    if (x >= 0 && x <= 9 && y >= 0 && y <= 9) {
        if (x + y <= 9) {
            answer++;
        }
    } else if ((x >= 10 && x <= 19 && y >= 0 && y <= 9) || (x >= 0 && x <= 9 && y >= 10 && y <= 19)) {
        if (x + y <= 18) {
            answer++;
        }
    }
}

```
② 当k = 10时，它存在三条屏障线（ y = -x + 10, y = -x + 19, y = -x + 28），如下图中 k = 10的线条（黄色）所示。同理对待，它将分成三个区间操作。一、当x∈[0, 9]且y∈[0, 9]时，得用 x + y <= 10 来衡量；二、当x∈[10, 19]且y∈[0,9]，或者x∈[0, 9]且y∈[10, 19]时，得用 x + y <= 19来衡量；三、当x∈[20, 29]且y∈[0, 9]，或者x∈[10, 19]且y∈[10, 19]，或者x∈[0, 9]且y∈[20, 29]时，得用 x + y <= 28 来衡量。将它们转化为通用代码。
```java []

class Solution {
    public int movingCount(int m, int n, int k) {
        //确定一共有几个区间
        int sectionNum = k < 9 ? 1 : k - 7;
        //横坐标的下限、上限，纵坐标的下限、上限，每个区间的（横坐标 + 纵坐标）的上限
        int iDown, iUp, jDown, jUp, ijUpper;
        int answer = 0;
        for (int s = 0; s < sectionNum; s++) {
            //对于每个区间，从右下角开始遍历
            iUp = s * 10 + 9;
            iDown = s * 10;
            jUp = 9;
            jDown = 0;
            ijUpper = (k - s) + s * 10;
            while (iDown >= 0) {
                //一个方块一个方块进行遍历
                for (int i = iDown; i <= iUp && i < m; i++) {
                    for (int j = jDown; j <= jUp && j < n; j++) {
                        //判断 横坐标 + 纵坐标 是否小于 该区间的 上限
                        if (i + j <= ijUpper)
                            answer++;
                    }
                }
                //从右下角遍历到左上角
                iUp -= 10;
                iDown -= 10;
                jUp += 10;
                jDown += 10;
            }
        }
        return answer;
    }
}

```

![移动范围.jpg](https://pic.leetcode-cn.com/01e3a750e6626f9fa5e885fe1d43cda0ae766465c6ad5db08d5cb7f125f11de1-%E7%A7%BB%E5%8A%A8%E8%8C%83%E5%9B%B4.jpg)

![双百.png](https://pic.leetcode-cn.com/d00e75185b4a4bf796dcefbc19bd9836c03f23d0bd58c37c2c1919857352441f-%E5%8F%8C%E7%99%BE.png)
