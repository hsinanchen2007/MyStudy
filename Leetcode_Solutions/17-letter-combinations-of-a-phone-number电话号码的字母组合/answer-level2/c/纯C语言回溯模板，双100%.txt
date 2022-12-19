
可以和https://leetcode-cn.com/problems/combinations/对比来看

回溯模板，解释一下trackBack中循环的j的意义

对于回溯题目，两个条件
1、最终输出的结果要求的长度，回溯总长度，这个用level来决定，初始为1
2、每次回溯的起始位置，对于最终结果中的每一个独立的小元素，其遍历的空间范围。

17这个题目，
level就是输出的字符串的长度，
对于每一个数字来说，起始位置就是0，比如3这个字符，我要遍历def这三个字符，从零开始一直到案件对应的字符串的长度

77这个题目
level就是k的长度
要求不能重复，所以这里的遍历空间使用i这个变量传入到了回溯函数中，使用j=i来控制



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define N 10000
typedef struct {
    int cnt;
    char a[5];
} num;

num nums[10] = {
    {0, '0'},
    {1, '0'},
    {3, "abc"},
    {3, "def"},
    {3, "ghi"},
    {3, "jkl"},
    {3, "mno"},
    {4, "pqrs"},
    {3, "tuv"},
    {4, "wxyz"},
};

void trackBack(char **ret, char *digits, int *returnSize, char *arr, int level, int cnt)
{
    if (!digits) {
        return;
    }

    if (level == cnt) {
        arr[cnt] = '\0';
        ret[*returnSize] = malloc(sizeof(char) * (cnt+1));
        memcpy(ret[(*returnSize)], arr, cnt+1);
        (*returnSize)++;
        return;
    }

    for (int j = 0; j < nums[digits[level] - '0'].cnt; j++) {
        arr[level] = nums[digits[level] - '0'].a[j];
        trackBack(ret, digits, returnSize, arr, level+1, cnt);
    }

}

char ** letterCombinations(char * digits, int* returnSize){
    if (!digits) return NULL;
    int cnt = strlen(digits);
    if (cnt == 0) {
        *returnSize = 0;
        return NULL;
    }
    char *arr = (char *)malloc(sizeof(char) * (cnt + 1));
    *returnSize = 0;
    char **a = (char **)malloc(sizeof(char*) * N);

    trackBack(a, digits, returnSize, arr, 0, cnt);
    return a;
}``
```
