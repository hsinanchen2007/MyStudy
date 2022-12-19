设巨无霸的数量为j, 小汉堡的数量为s, 得到以下方程组:
4 * j + 2 * s = tomatoSlices
j + s = cheeseSlices
解得
j = (tomatoSlices - 2*cheeseSlices) / 2
s = cheeseSlices - j
最后判断j和s是否大于等于0的整数

```java
public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    int j = (tomatoSlices - 2 * cheeseSlices) / 2;
    int s = cheeseSlices - j;

    if (j < 0 || s < 0 || j * 4 + s * 2 != tomatoSlices || j + s != cheeseSlices)
        return new ArrayList<>();
    else
        return Arrays.asList(j, s);
}
```
