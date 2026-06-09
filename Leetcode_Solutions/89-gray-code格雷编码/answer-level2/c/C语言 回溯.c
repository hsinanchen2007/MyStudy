### 解题思路
1.需要借助字符串来表示二进制，将字符串转化为int类型，存到res。
2.visited数组：以二进制转化为十进制的数字作为数组index 标识这个十进制数是否已经生成过了
dfs函数的书写：走的每一步都要存到res里



### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 int* grayCode(int n, int* returnSize) {
    int len = 1 << n;
    int* a = calloc(len,sizeof(int));
    for(int i = 0;i < len;i++)
        a[i] = i ^ (i >> 1);
    *returnSize = len;
    return a;
}
 */
int str2int(char *str, int n){
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum * 2 + (str[i] - '0');
    }
    return sum;
}

void dfs(int n, int num, int *returnSize, int *res, char *str, int *visited)
{
    if (num == (*returnSize)) { // 全部找到了
        return;
    }
    
    for (int i = 0; i < n; i++) {
        str[i] = (str[i] == '0' ? '1' : '0');
        if (visited[str2int(str, n)] == 0) {
            visited[str2int(str, n)] = 1;
            res[*returnSize] = str2int(str, n);
            (*returnSize)++;
            dfs(n, num, returnSize, res, str, visited);
        } else {
            str[i] = (str[i] == '0' ? '1' : '0');
        }
    }
}

int* grayCode(int n, int* returnSize){
    int num = 1 << n;
    int *res = (int *)malloc(num * sizeof(int));
    
    char *str = (char *)calloc(n + 1, sizeof(char));
    for (int i = 0; i < n; i++) {
        str[i] = '0';
    }
    int *visited = (int *)calloc(num, sizeof(int));
    
    
    *returnSize = 1;
    res[0] = 0;
    visited[str2int(str, n)] = 1;
    dfs(n, num, returnSize, res, str, visited);
    return res;    
}
```