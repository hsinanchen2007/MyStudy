### 解题思路
1.从n递归到1，从1开始输出，依次解析
### 代码

```c
char * countAndSay(int n)
{
    char *ret = NULL;
    char *out = NULL;
    int i = 0;
    int j = 1;
    int k = 0;
    int len = 0;

    if (n == 1) {
        ret = (char *)malloc(sizeof(char) * 2);
        ret[0] = '1';
        ret[1] = '\0';
        return ret;
    }

    ret = countAndSay(n - 1);
    len = strlen(ret);
    out = (char *)malloc(sizeof(char) * (len * 2 + 1));
    while (ret[i] != '\0') {
        if (ret[i + 1] == '\0') {
            out[k++] = j + '0';
            out[k++] = ret[i];
            out[k++] = '\0';
            break;
        }
        if (ret[i] == ret[i + 1]) {
            j++;
        } else {
            out[k++] = j + '0';
            out[k++] = ret[i];
            j = 1;
        }
        i++;
    }

    return out;
}
```