### 解题思路
有个小技巧： 计算相邻字符的个数，要把最后的结束符号计算进去，防止丢失；

### 代码

```c
#define MAX_LEN 100000

void dfs(char* value, int n)
{
    char temp[MAX_LEN] = {0};
    int num = 1;
    int k = 0;

    if (n == 1) {
        value[0] = '1';
        return;
    }

    dfs(value, n - 1);
    for (int i = 1; i <= strlen(value); i++) {
        if (value[i] != value[i - 1]) {
            temp[k++] = num + '0';
            temp[k++] = value[i - 1];
            num = 1;
        } else {
            num++;
        }
    }
    strcpy(value, temp);
    return;
}
char * countAndSay(int n){
    char* value = NULL;

    value = (char*)malloc(sizeof(char) * MAX_LEN);
    memset(value, 0, sizeof(char) * MAX_LEN);

    dfs(value, n);
    return value;
}
```