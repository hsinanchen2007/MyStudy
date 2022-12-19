### 解题思路
核心问题：如果将问题退化到d是一个一维字符串的话，s如何删减能够构成d。思路就是利用两个指针p和q比对两个字符串的每一位，如果相等的话，指针p和q就同时向后移动。如果不相等，就只将p向后移动一位。最后如果q能够移动到最后的话，说明p通过删减部分字符能够构成q。如果p移动到了末尾，q却依然没能移动到最后的话，说明p无论如何删减都是没办法构成q。这里需要注意的是，字符串的删减是不会改变字符顺序的，所以如果仅仅通过统计q字符串的字母个数的方法是无法判定的，因为丢失了字符串是有顺序的这个特性。

### 代码

```c
char * findLongestWord(char * s, char ** d, int dSize){
    char *result = "";
    int max = -1;
    for (int i = 0; i < dSize; ++i) {
        char *p = s, *q = d[i];
        int j = 0, k = 0;
        while (p[j] != '\0' && q[k] != '\0') {
            if (p[j] == q[k]) {
                ++k;
            } 
            ++j;
        }
        if (q[k] == '\0') {
            if (k > max) {
                max = k;
                result = q;
            } else if (k == max) {
                if (q[0] - result[0] < 0) {
                    max = k;
                    result = q;
                }
            } else {

            }
        }
    }
    
    return result;
}
```