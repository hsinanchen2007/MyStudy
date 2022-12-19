### 解题思路
我也不知道我用的算是什么方法(萌新瑟瑟发抖),思路就是顺序遍历一遍s,记录重复的字符数量,在发现不同字符时写入数量与当前字符.
![image.png](https://pic.leetcode-cn.com/baed24fc35d7e1f48180b746ff98d55daa9fe8adaca4ea6bc3b11156e189cc6a-image.png)

### 代码

```c
#include <stdlib.h>
char * compressString(char * s){
    if (s == NULL || s[0] == '\0') {
        return s;
    }
    char * rs = malloc(sizeof(char) * 50010);
    rs[0] = s[0];
    int rssize = 0;
    int ssize = 1;
    int many = 1;
    int manysize, nmany;
    for (; s[ssize] != '\0'; ssize++) {
        if (s[ssize] == rs[rssize]) {
            many++;
        } else {
            manysize = 0;
            nmany = many;
            while(nmany > 0) {
                nmany /= 10;
                manysize++;
            }
            rssize += manysize;
            if (rssize > 49998) {
                return s;
            }
            manysize = rssize;
            while(many > 0) {
                rs[manysize] = (many % 10) + '0';
                manysize--;
                many /= 10;
            }
            rssize++;
            rs[rssize] = s[ssize];
            many = 1;
        }
    }
    manysize = 0;
    nmany = many;
    while(nmany > 0) {
        nmany /= 10;
        manysize++;
    }
    rssize += manysize;
    manysize = rssize;
    while(many > 0) {
        rs[manysize] = (many % 10) + '0';
        manysize--;
        many /= 10;
    }
    rssize++;
    rs[rssize] = '\0';
    printf("%d", ssize);
    if (ssize > rssize) {
        return rs;
    } else {
        return s;
    }
}
```