![image.png](https://pic.leetcode-cn.com/853fc0cf5c4ca4c22efde2a35ac29e186d4a94a0e067c4cc835912561ecf2fd2-image.png)

其实C语言出现100%很容易, 我这么菜一定是哪里有问题了 :), 问题的核心其实就是确认返回整数的范围, 弄明白为什么返回数小于等于n后面就水到渠成了， 为了节省空间使用了bitset， 一个char通常为八位能够表示八个数，char数组就可以表达多个数字了, BITSLOT获取char数组的下标， BITMASK向左移动以赋值， BITTEST做与运算查看是否存在很简单~

```c
#include <limits.h>        /* for CHAR_BIT */
#include <string.h>
#include <stdlib.h>

#define BITMASK(b) (1 << ((b) % CHAR_BIT))
#define BITSLOT(b) ((b) / CHAR_BIT)
#define BITSET(a, b) ((a)[BITSLOT(b)] |= BITMASK(b))
#define BITTEST(a, b) ((a)[BITSLOT(b)] & BITMASK(b))

int firstMissingPositive(int *nums, int numsSize);


int firstMissingPositive(int *nums, int numsSize) {
    u_char *table = malloc(numsSize/8 + 1);
    memset(table, 0, numsSize/8 + 1);
    if (nums == NULL) {
        return -1;
    }

    int *step = nums;
    int size = numsSize;
    while (size-- > 0) {
        //非正整数跳过
        if (*step > 0 && *step <= (numsSize + 1)) {
            BITSET(table, *step);
        }
        step++;
    }


    int result;
    for (result = 1; result <= numsSize; result++) {
        if (!BITTEST(table, result)) {
            free(table);
            return result;
        }
    }
    free(table);
    return result;
}
```
