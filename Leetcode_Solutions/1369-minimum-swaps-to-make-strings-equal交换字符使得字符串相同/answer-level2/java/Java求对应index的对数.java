将两个输入的等长字符串转为字符数组, 则在对应`0 <= index < s1.length()`的index中, `xy`表示两个字符数组相同位置`x<->y`的对数, `yx`表示`y<->x`的对数, 有如下三种可能:
1. 两个字符数组对应位置都为`x`或者都为`y`, 则不需要交换, `ans = 0`;
2. 两个字符数组对应位置为`x<->y`或者`y<->x`, 则又有以下两种情况:
    - 首先, `x<->y`与`x<->y`交换位置, 只需要交换一次即可成为`x<->x`/`y<->y`, `y<->x`与`y<->x`同理. 则`ans = ans + xy/2 + yx/2`
    - 其次, 剩下的就只有`x<->y`和`y<->x`了, 这里也有三种情况:
        - `x<->y`和`y<->x`各一个, 则需要两次交换才能成为`x<->x`/`y<->y`, ans += 2(等价于`ans = ans + xy%2 +yx%2`);
        - `x<->y`和`y<->x`都没有, 则ans不变
        - `x<->y`和`y<->x`只有其中一对有一个, 则无法交换, `ans = -1`

```java
public int minimumSwap(String s1, String s2) {
    char[] chars1 = s1.toCharArray();
    char[] chars2 = s2.toCharArray();

    int xy = 0;
    int yx = 0;

    for (int i = 0; i < s1.length(); i++) {
        if (chars1[i] == chars2[i]) {
            continue;
        } else if (chars1[i] == 'x') {
            xy++;
        } else {
            yx++;
        }
    }
    // 如果为xy<->xy或者yx<->yx, 则需要一次交换即可
    int ans = xy / 2 + yx / 2;
    // 剩下的xy<->yx则需要两次交换才可以, 如果xy<->yx等于0, 则不需要交换即xy+yx=0
    // 否则, xy<->yx各一对, 则需要交换两次, 即xy+yx=2
    // 如果, xy<->yx只有其中一对, 则无法组合, 返回-1
    xy %= 2;
    yx %= 2;
    return (xy + yx) == 1 ? -1 : ans + xy + yx;
}
```