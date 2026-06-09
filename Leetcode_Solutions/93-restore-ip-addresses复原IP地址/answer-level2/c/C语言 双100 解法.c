### 执行结果
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :6.7 MB, 在所有 C 提交中击败了100.00%的用户

### 解题思路
1.排除大于12 小于4的非法长度
2.4个IP地址的特征每个不超过3个
3.从左向右，4个IP(1-3)位组合
4.满足条件：4个加在一起长度等于原len；都在0-255，并且没有0前缀的数字，例如： 01 00 001 

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** restoreIpAddresses(char * s, int* returnSize){
    if (s == NULL || returnSize == NULL) {
        return NULL;
    }
    *returnSize = 0;

    int len = strlen(s);
    int cnt = 0;
    if (len > 12 || len < 4) {
        return NULL;
    }

    char **array = (char **)malloc(1000 * sizeof(char *));
    /* str 1位 2位 3位*/
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 && (i + 1 + j) < len; j++) {
            /* begin i + 1*/
            for (int m = 0; m < 3 && (j + 1 + m) < len; m++) {
                /* begin j + 1*/
                    for (int n = 0; n < 3 && (m + 1 + n) < len; n++) {
                        /* begin m + 1*/
                        if (len != (4 + i + j + m + n)) {
                            continue;
                        }
                        char str1[4] = {0};
                        char str2[4] = {0};
                        char str3[4] = {0};
                        char str4[4] = {0};
                        memcpy(str1, s, i + 1);
                        memcpy(str2, s + i+1, j + 1);
                        memcpy(str3, s + i+1 + j+1, m + 1);
                        memcpy(str4, s + i+1 + j+1 + m+1, n + 1);

                        int num1 = atoi(str1);
                        if (num1 > 255) {
                            continue;
                        }
                        int num2 = atoi(str2);
                        if (num2 > 255) {
                            continue;
                        }
                        int num3 = atoi(str3); 
                        if (num3 > 255) {
                            continue;
                        }
                        int num4 = atoi(str4);
                        if (num4 > 255) {
                            continue;
                        }

                        char tmp[16] = {0};
                        sprintf(tmp, "%s.%s.%s.%s", str1, str2, str3, str4);
                        char *out = malloc(16);
                        memset(out, 0 ,16);
                        sprintf(out, "%d.%d.%d.%d", num1 , num2, num3, num4);
                        if (strlen(tmp) != strlen(out)) {
                            //printf("find 000 tmp:%s\n",tmp);
                            free(out);
                            out = NULL;
                            continue;
                        }
                        array[cnt++] = out;
                    }    
            }
        }        
    }

    if (cnt == 0) {
        free(array);
        array = NULL;
    }
    *returnSize = cnt;
    return array;
}
```