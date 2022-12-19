### 解题思路
典型是双指针处理字符串题型，这里特殊的地方在于，从右向左处理，更加方便。

另外双指针处理的模板，需要注意在退出后，要检查最后一次剩余的处理。

![image.png](https://pic.leetcode-cn.com/2707393f06c7c2b3138f2a94098fba898ffde601be2aef205177e030eb843d92-image.png)


### 代码

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

//【算法思路】双指针。典型的双指针字符操作。这里需要反向遍历，即从右向左
char * reverseWords(char * s){
    if(strlen(s) == 0) {
        return s;
    }

    int slen = strlen(s);

    char *ret = (char *)calloc(slen + 1, sizeof(char));
    int rsize = 0;

    //从右向左遍历取词，即先移动ll
    int ll = -1, rr = -1;

    //后面处理都是从右向左
    //首先找到第一个非空字符
    for(int i = slen - 1; i >= 0; i--) {
        if(s[i] != ' ') {
            ll = i;
            rr = i;
            break;
        }
    }

    if(ll == -1) {
        return "";
    }

    while(ll >= 0) {
        if(s[ll] != ' ') {
            ll--;
            continue;
        }

        //此时ll为空，rr指向最后一个非空字符
        if(ll != rr) {
            for(int i = ll + 1; i <= rr; i++) {
                ret[rsize++] = s[i];
            }
            ret[rsize++] = ' ';
        }

        ll--;
        rr = ll;
    }

    //处理最后结束的单词
    if(ll != rr) {
        //此时ll为空，rr指向最后一个非空字符
        for(int i = ll + 1; i <= rr; i++) {
            ret[rsize++] = s[i];
        }
        ret[rsize++] = '\0';
    } else {
        //将最后多出的空格去掉
        ret[rsize - 1] = '\0';
    }

    return ret;
}
```