### 解题思路
1. 首先考虑异常情况，k=0直接返回空数组；
2. 当长短板一样长时，只有一种情况，直接返回；
3. 先统计全部是短板的情况，必然为最短，然后取出一个短板换成长板即可，最终到全部为长板结束，数组也不会重复且有序。

![image.png](https://pic.leetcode-cn.com/34e362777d8daa22507ba8d2bb45ed1ec84cf8202b9be61901821cceb5f2106b-image.png)


### 代码

```java
class Solution {
    public int[] divingBoard(int shorter, int longer, int k) {
        // 异常处理
        if (k == 0) {
            return new int[]{};
        }
        // 长板与短板一样长，则只有一种
        if (shorter == longer) {
            return new int[]{shorter * k};
        }
        int[] ints = new int[k + 1];
        int index = 0;
        for (int i = k; i >= 0; i--) {
            ints[index++] = (shorter * i) + (longer * (k - i));
        }
        return ints;
    }
}
```