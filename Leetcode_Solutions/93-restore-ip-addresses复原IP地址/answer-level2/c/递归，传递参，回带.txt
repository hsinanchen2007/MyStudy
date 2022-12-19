### 解题思路
递归遍历ip地址的段，临时数组记录过程ip数据,满足条件申请内存挂在返回值上。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void checkVaild(char *subStr, int index, char *ip ,char**out, int *numbers)
{
    int val = 0;
    int sublen = strlen(subStr);
    int iplen  = strlen(ip) ;
    if (!sublen) {
        return;
    }
    //printf("substr %s, ip %s index %d, number %d, sublen %d, iplen %d\n",subStr, ip, index, *numbers,sublen,iplen);
    if (index == 4) {
        if (strlen(subStr) > 3 || strlen(subStr) < 1) {
            return;
        } else {
            out[*numbers] = (char*)malloc(16 * sizeof(char));
            val = atoi(subStr);
            if (strlen(subStr) == 1) {
                if (subStr[0] <= '9') {
                    ip[iplen] = subStr[0];
                    strncpy(out[*numbers], ip, 16);
                    *numbers += 1;
                    return;
                }
            } else if (sublen == 2) {
                if (val <= 99 && subStr[0] != '0') {
                    ip[iplen] = subStr[0];
                    ip[iplen+1] = subStr[1];
                    strncpy(out[*numbers], ip, 16);
                    *numbers += 1;
                    return;
                }
            } else if (sublen == 3) {
                if (val <= 255 && subStr[0] != '0') {
                    ip[iplen] = subStr[0];
                    ip[iplen+1] = subStr[1];
                    ip[iplen+2] = subStr[2];
                    strncpy(out[*numbers], ip, 16);
                    *numbers += 1;
                    return ;
                }
            }
            free(out[*numbers]);
            out[*numbers] = NULL;
            return ;
        }
        return;
    }

    for (int i = 1; i < 4 && i < sublen; i++) {
        if (i == 1) {
            if (subStr[0] > '9')
                break;
        }
        if (i == 2) {
            if (subStr[0] == '0'|| subStr[0] > '9' || subStr[1] > '9')
                break;
        }
        if (i == 3) {
            char t[4];
            t[0] = subStr[0];
            t[1] = subStr[1];
            t[2] = subStr[2];
            t[3] = 0;
            if(atoi(t) > 255 || t[0] == '0')
                break;
        }
        memset(ip+iplen,0,16-iplen);
        (void)strncat(ip,subStr,i);
        ip[strlen(ip)] = '.';

        checkVaild(subStr+i, index+1, ip, out, numbers);
    }
    return ;
}
char ** restoreIpAddresses(char * s, int* returnSize){
    char **out = NULL;
    int len = strlen(s);
    char ip[16] = {0};

    *returnSize = 0;
    out = (char **)malloc(1000 * sizeof(char*));
    memset(out, 0, 1000 * sizeof(char*));

    if (len < 4 || len > 12) {
        return NULL;
    }
    checkVaild(s, 1, ip, out, returnSize);
    return out;
}
```