```
public int minimumSwap(String s1, String s2) {
    // step1. 对比数组长度, 如果不一致则直接 -1 如果 两个字符串equals 则直接 0
    if (s1.length() != s2.length()) {
        return -1;
    }
    if (s1.equals(s2)) {
        return 0;
    }

    // step2. 去除对齐的冗余
    char[] c1 = s1.toCharArray();
    char[] c2 = s2.toCharArray();

    char[] f1 = new char[c1.length];
    char[] f2 = new char[c2.length];

    int index = 0;
    for (int i = 0; i < c1.length; i++) {
        if (c1[i] != c2[i]) {
            f1[index] = c1[i];
            f2[index] = c2[i];
            index++;
        }
    }

    // step3. 将数组以2个为一组进行分组
    // case1: 如果 xx, yy 或者 yy, xx 则交换 1 次
    // case2: 如果 xy, yx 或者 yx, xy 则交换 2 次
    // 否则 直接范围 -1, 情况可能有 xx, yx等
    // 统计count时, 有一个trip, 
    // 如果是case2的情况可以将两组进行相互 互换位置 进行消融交换次数, 所以用了一个xr布尔变量, 当只剩下最后一组无法消融直接累加即可
    // 如果是case1的情况则无法消融统计直接累加
    int count = 0;
    boolean xr = false;
    for (int i = 0; i < f1.length; i = i + 2) {
        if (f1[i] == '\u0000') {
            continue;
        }
        if (f1[i] == 'x' && f1[i + 1] == 'x' && f2[i] == 'y' && f2[i + 1] == 'y') {
            count++;
        } else if (f1[i] == 'y' && f1[i + 1] == 'y' && f2[i] == 'x' && f2[i + 1] == 'x') {
            count++;
        } else if (f1[i] == 'x' && f1[i + 1] == 'y' && f2[i] == 'y' && f2[i + 1] == 'x') {
            if (!xr) {
                count = count + 2;
                xr = true;
            } else {
                xr = false;
            }
        } else if (f1[i] == 'y' && f1[i + 1] == 'x' && f2[i] == 'x' && f2[i + 1] == 'y') {
            if (!xr) {
                count = count + 2;
                xr = true;
            } else {
                xr = false;
            }
        } else {
            return -1;
        }
    }

    return count;
}
```
