### 解题思路
乘二后面每两个减一 可以替换成乘二前面一个减一
### 代码

```c
int brokenCalc(int X, int Y){
    int x2count = 0;
    int d1count = 0;
    int count = 0;
    for (; X < Y; X*=2) {
        x2count++;
    }
    d1count = X - Y;
    while (true) {
        if (x2count == 0) {
            count += d1count;
            break;
        } else {
            x2count--;
            count++;
            count += d1count%2;
            d1count /= 2;
        }
    }
    return count;
}
```