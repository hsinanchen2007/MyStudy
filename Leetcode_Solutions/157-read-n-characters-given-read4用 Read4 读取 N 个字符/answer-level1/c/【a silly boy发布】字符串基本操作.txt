![3E3207BA-5E69-46A8-BA56-EB358016CD8B.jpeg](https://pic.leetcode-cn.com/6e883a6302d755c65b372960b51446fd557d027a19eada9f2e8ba6a6265baf4e-3E3207BA-5E69-46A8-BA56-EB358016CD8B.jpeg)

```
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf);
 */

/**
 * @param buf Destination buffer
 * @param n   Number of characters to read
 * @return    The number of actual characters read
 */
int _read(char* buf, int n) {
    int nChu = n / 4;
    int nYu = n % 4;
    int i;
    int returnValRead4;
    for (i = 0; i < nChu; i++) {
        returnValRead4 = read4(&(buf[i * 4]));
        // 1-1 当前不够
        if (returnValRead4 != 4) {
            return 4 * i + returnValRead4;
        }
    }
    if (nYu == 0) {
        return n;
    }
    // 2取整数够
    returnValRead4 = read4(&(buf[nChu * 4]));
    //printf("returnValRead4: %d, nYu: %d\n", returnValRead4, nYu);
    if (returnValRead4 == nYu) {
        return n;
    } else if (returnValRead4 < nYu) {
        // 2-1余数不够
        return n - (nYu - returnValRead4);
    } else {
        // 2-2余数够
        buf[n] = '\0';
        return n;
    }
}
```
