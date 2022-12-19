### 解题思路
返回所有长度为 N 且满足其每两个连续位上的数字之间的差的绝对值为 K 的非负整数。

请注意，除了数字 0 本身之外，答案中的每个数字都不能有前导零。例如，01 因为有一个前导零，所以是无效的；但 0 是有效的。

你可以按任何顺序返回答案。

 

示例 1：

输入：N = 3, K = 7
输出：[181,292,707,818,929]
解释：注意，070 不是一个有效的数字，因为它有前导零。





数字从高位往低位构造,  往后如下递归
cur = cur*10 + cur - K;
cur = cur*10 + cur + K;

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *res;
int g_index=0;

int dfs(int cur, int N,int K){
    int last;

    if(N<=0){　　//结束时才加入统计，　与之前320题，单词缩写一样
        res[g_index++] = cur;
        return;
    }
    if(cur){
        last = cur%10;
        if(last - K >=0)
            dfs(cur*10 + last - K,N-1,K);
        if(last + K <=9 && last+K != last-K)
            dfs(cur*10 + last + K,N-1,K);
    }
}

int* numsSameConsecDiff(int N, int K, int* returnSize){
    int i,j;

    res = malloc(2000*sizeof(int));
    memset(res,0,2000*sizeof(int));
    g_index = 0;

    if(N==1){
        for(i=0;i<=9;i++)
            res[i] = i;
        *returnSize = 10;
        return res;
    }

    for(i=1;i<=9;i++)
        dfs(i,N-1,K);
    
    *returnSize = g_index;
    return res;
}
```