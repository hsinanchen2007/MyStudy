### 解题思路
一个指针作为原地修改的索引，另外两个快慢指针负责计树和定位。
注意 一个字母重复的次数可能超过10，这样就无法通过 + '0'来进行转换，需要做一次整数转字符串，最后别忘记前后换位置。

### 代码

```c
int compress(char* chars, int charsSize){
    int cur = 0;
    int i = 0;
    int j = 0;
    int cnt;
    while (i < charsSize) {
        cnt = 0;
        while (j < charsSize && chars[j] == chars[i]) {
            j++;
            cnt++;
        }
        chars[cur++] = chars[i];
        // 若cnt大于10
        if (cnt > 1) {
            char intToChr[10];
            int k = 0;
            while (cnt > 0) {
                intToChr[k++] = cnt % 10 + '0';
                cnt = cnt / 10;
            }
            intToChr[k] = '\0';
            k = k - 1;
            for (; k > -1; k--) {
                chars[cur++] = intToChr[k];
            }
        }
        i = j;
    }
    charsSize = cur;
    return charsSize;
}
```