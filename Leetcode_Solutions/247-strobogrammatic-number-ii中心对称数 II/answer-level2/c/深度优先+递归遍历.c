### 解题思路
1,可以当作摆列组合问题，给定n个位置，位每个位置挑选一个数，使得最终凑成的n位的整数为中心对称数
2,考虑奇对称和偶对称两种情况，对于偶对称，从中间一分为二，两边的数互相对称就行了；对于奇对称，我们还有考虑中间位置的对称；
3,中心位置的那个数必须是自镜像的，就是旋转180度仍然等于自己，只能从0，1，8三个数中挑选，用selfMirrors数组保存
4,剩下两边的对称，我们只考虑左半边就行，等左半边确定，有半边直接取左半边各个对应位置的对称数即可，左边位置数字的选择只要是对称数就可以，0，1，6，8，9都可以用，我们用mirrors数组保存
5,另外特殊考虑一下左起第一位不能为0的情况
6,从左边第一位起，进行深度优先遍历，使得每个位置，每一种可能的数字组合都遍历到
7,递归结束的条件是当前位置到达中间位置，并根据是否奇对称处理下中心位置的情况即可
8,递归过程中用一个长度为n的栈stack来保存截止当前位置的数字组合，且每次入栈一个数字，我们奖其对称数填在对称位置，方便本次深度递归结束时直接输出一个OK的字符串

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char mirrors[5] = {'0', '1', '6', '8', '9'};
char selfMirrors[3] = {'0', '1', '8'};

char getMirror(char num)
{
    switch(num) {
        case '0':
        case '1':
        case '8':
            return num;
        case '6':
            return '9';
        case '9':
            return '6';
        default:
            return 'X';
    }
}

void DFS(int n, char **ret, int *wi, char *stack, int sp, int halfLen, int hasMid)
{
    if (sp >= halfLen) {
        if (!hasMid) {
            memcpy(ret[(*wi)++], stack, n);
            return;
        }
        for (int i = 0; i < 3; i++) {
            stack[sp] = selfMirrors[i];
            memcpy(ret[(*wi)++], stack, n);
        }
        return;
    }
    for (int i = (sp == 0) ? 1 : 0; i < 5; i++) {
        stack[sp] = mirrors[i];
        stack[n - sp - 1] = getMirror(mirrors[i]);
        DFS(n, ret, wi, stack, sp+1, halfLen, hasMid);
    }
}

char ** findStrobogrammatic(int n, int* returnSize){
    int hasMid = (n % 2 == 1)? 1 : 0;
    int halfLen = n / 2;
    int totalNum = 1;
    if (n < 1)
        return NULL;
    for (int i = 0; i < halfLen; i++) {
        totalNum = (i == 0) ? 4 : totalNum * 5;
    }
    totalNum = (hasMid) ? totalNum * 3 : totalNum;
    printf("totalNum = %d\n", totalNum);
    char **ret = (char **)malloc(sizeof(char *) * totalNum);
    for (int i = 0; i < totalNum; i++) {
        ret[i] = (char *)malloc(sizeof(char) * (n+1));
        memset(ret[i], 0, sizeof(char) * (n + 1));
    }
    int wi = 0;
    int sp = 0;
    char *stack = (char *)malloc(sizeof(char) * (n+1));
    printf("start DFS...\n");
    DFS(n, ret, &wi, stack, sp, halfLen, hasMid);
    *returnSize = totalNum;
    return ret;
}
```