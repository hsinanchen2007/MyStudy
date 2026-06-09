### 解题思路
直接异或A与B
数1的个数即可。

### 代码

```c
int convertInteger(int A, int B) {
    int c, cnt, i;
    c = A ^ B;
    i = cnt = 0;
    while (i < 32) {
        int tmp = (c >> i) & 0x01;
        if (tmp == 1) {
            cnt++;
        }
        i++;
    }
    return cnt;
}
```