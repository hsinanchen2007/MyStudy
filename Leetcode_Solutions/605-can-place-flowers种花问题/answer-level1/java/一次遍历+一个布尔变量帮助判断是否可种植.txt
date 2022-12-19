# 思路
1. 直接遍历，布尔值isAble保存当前是否可种植，count保存可种植数量；
2. 若遍历到0：
    - 当前可种植，则种植数count+1，修改isAble;
    - 当前不可种植，下一个地块可种植，修改isAble.
3. 若遍历到1：
    - 当前可种植，（实际上已经种植了），修改isAble为false;
    - 当前不可种植，撤销前一次种植，count-1.

# 代码
```
public static boolean canPlaceFlowers(int[] flowerbed, int n) {
    int len = flowerbed.length;
    boolean isAble = true;
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (flowerbed[i] == 0) {
            count += (isAble ? 1 : 0);
            isAble = !isAble;
        } else {
            if (!isAble) {
                count--;
            }
            isAble = false;
        }
    }
    return (n <= count) ? true : false;
}
```


# 总结
- 时间复杂度O(n)
- 空间复杂度O(1)