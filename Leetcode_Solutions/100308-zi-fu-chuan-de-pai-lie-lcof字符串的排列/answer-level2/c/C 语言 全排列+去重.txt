### 解题思路
此处撰写解题思路
（1）全排列
首先求得所有可能出现在第一个位置上的字符，即把第一个字符和后边所有的字符交换；
固定第一个字符，求后面所有字符的排列。

如abc:
第一步：将第一行数据分别和第二行和第三行数据交换
a	b	c
b	a	c
c	a	b
 	 	 

第二步：保持第一列不变，将第二行数据分别和第三行数据交换
a	c	b
b	c	a
c	b	a

交换完毕，显然，要用到递归的知识。

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cnt = 0;
void mypermutation(char *s, char *begin, char **arr, int sz)
{
    if (*begin == '\0') {
        memcpy(arr[cnt], s, sz);
        cnt++;
        return;
    }
    for (char *ch = begin; *ch != '\0'; ch++) {
        char temp = *ch;
        *ch = *begin;
        *begin = temp;

        mypermutation(s, begin + 1, arr, sz);

        temp = *ch;
        *ch = *begin;
        *begin = temp;
    }
}

char** permutation(char* s, int* returnSize){
    int sz = strlen(s);
    char **arr = NULL;
    int i;

    cnt = 0;
    *returnSize = 1;
    for (i = 1; i <= sz; i++) {
        *returnSize *= i;
    }
    arr = (char **)malloc(sizeof(char *) * (*returnSize));
    for (i = 0; i < *returnSize; i++) {
        arr[i] = (char *)malloc(sizeof(char) * (sz + 1));
        memset(arr[i], 0, sizeof(char) * (sz + 1));
    }

    mypermutation(s, s, arr, sz);

    return arr;

}
```



（2）去重
对122，第一个数1与第二个数2交换得到212，然后考虑第一个数1与第三个数2交换，此时由于第三个数等于第二个数，所以第一个数不再与第三个数交换。再考虑212，它的第二个数与第三个数交换可以得到解决221。此时全排列生成完毕。

这样我们也得到了在全排列中去掉重复的规则——去重的全排列就是从第一个数字起每个数分别与它后面非重复出现的数字交换。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cnt = 0;
void swap(char *p1, char *p2)
{
    char ch = *p1;
    *p1 = *p2;
    *p2 = ch;
}

bool isSwap(char *begin, char *end)
{
    char *ch;
    for (ch = begin; ch != end; ch++) {
        if (*ch == *end) {
            return false;
        }
    }

    return true;
}

void mypermutation(char *s, char *begin, char **arr, int sz)
{
    if (*begin == '\0') {
        memcpy(arr[cnt], s, sz);
        cnt++;
        return;
    }
    for (char *ch = begin; *ch != '\0'; ch++) {
        if (isSwap(begin, ch)) {
            swap(ch, begin);
            mypermutation(s, begin + 1, arr, sz);
            swap(ch, begin);
        }
    }
}

char** permutation(char* s, int* returnSize){
    int sz = strlen(s);
    char **arr = NULL;
    int i;

    cnt = 0;
    *returnSize = 1;
    for (i = 1; i <= sz; i++) {
        *returnSize *= i;
    }
    arr = (char **)malloc(sizeof(char *) * (*returnSize));
    for (i = 0; i < *returnSize; i++) {
        arr[i] = (char *)malloc(sizeof(char) * (sz + 1));
        memset(arr[i], 0, sizeof(char) * (sz + 1));
    }

    mypermutation(s, s, arr, sz);
    *returnSize = cnt;
    return arr;
}

```