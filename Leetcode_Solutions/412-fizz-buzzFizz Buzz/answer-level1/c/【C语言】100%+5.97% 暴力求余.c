### 解题思路
思路很简单，就是遍历求余。比的是实现速度。这次还是用了46mins，哎，需要控制在30mins内完成。
![image.png](https://pic.leetcode-cn.com/0c21fd89c97b272a10fd124eb6ce1ce6363e1cf202955700bc2aec2ae25dad83-image.png)


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char ** fizzBuzz(int n, int* returnSize){
    int i, j;
    char **ret = NULL;
    ret = (char **)malloc(n * sizeof(char *));
    memset(ret, 0x00, n * sizeof(char *));

    for (i = 0, j = 1; i < n; i++, j++) {
        if ((j % 3 == 0) && (j % 5 == 0)) {
            ret[i] = "FizzBuzz";
            // printf("%s\n",ret[i]);
        }
        else if(j % 3 == 0) {
            ret[i] = "Fizz";
            // printf("%s\n",ret[i]);
        }
        else if(j % 5 == 0) {
            ret[i] = "Buzz";
            // printf("%s\n",ret[i]);
        }
        else {
            ret[i] = (char *)malloc(100 * sizeof(char));
            memset(ret[i], 0x00, 100 * sizeof(char));
            sprintf(ret[i], "%d", j);
            // printf("%s\n",ret[i]);
        }
    }

    *returnSize = n;
    return ret;
}
```