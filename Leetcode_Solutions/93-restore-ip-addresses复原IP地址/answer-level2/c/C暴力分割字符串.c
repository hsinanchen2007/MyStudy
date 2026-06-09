### 解题思路
![image.png](https://pic.leetcode-cn.com/aaa92bf654b4503ed244e60d52d6d4256f49c985deabdc3aeea60e416e06eef3-image.png)

IP地址格式：xxx.xxx.xxx.xxx,其中 1 <= xxx <=255, 用3个.分割字符串，统计其中有效的ip地址
要剔除长度大于1且以0开头的地址

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** restoreIpAddresses(char * s, int* returnSize){
    int srcLen = strlen(s);
    char **retStr = malloc(sizeof(char *) *1024);
    *returnSize = 0;
    if (srcLen < 4) {
        return retStr;
    }

    //IP地址格式：xxx.xxx.xxx.xxx,其中 1 <= xxx <=255, 用3个.分割字符串，统计其中有效的ip地址
    char s1[4], s2[4], s3[4], s4[4];
    char *p;
    int len1, len2, len3, len4;
    for (int i = 0; i < srcLen - 3 && i < 3; i++) {
        if (s[0] == '0' && i > 0) {
            //第1个字符是0时，不需要考虑后面的字符了
            break;
        }
        for (int j = i + 1; j < srcLen - 2 && j < i + 4; j++) {
            if (s[i + 1] == '0' && j > i + 1) {
                //第1个字符是0时，不需要考虑后面的字符了
                break;
            }
            for (int k = j + 1; k < srcLen - 1 && k < j + 4; k++) {
                if (s[j + 1] == '0' && k > j + 1) {
                    //第1个字符是0时，不需要考虑后面的字符了
                    break;
                }

                strncpy(s1, s, i + 1);
                s1[i + 1] = '\0';

                p = s + i + 1;
                strncpy(s2, p, j - i);
                s2[j - i] = '\0';

                p = p + j - i;
                strncpy(s3, p, k - j);
                s3[k - j] = '\0';

                p = p + k - j;
                len4 = strlen(p);
                if (len4 > 3 || len4 == 0) {
                    continue;
                }
                strcpy(s4, p);
                s4[len4] = '\0';

                //printf("%s.%s.%s.%s 1111\n", s1, s2, s3, s4);
                //剔除比255大的地址
                len1 = strlen(s1);
                if (len1 == 3 && strncmp(s1, "255", len1) > 0) {
                    continue;
                }
                len2 = strlen(s2);
                if (len2 == 3 && strncmp(s2, "255", len2) > 0) {
                    continue;
                }
                len3 = strlen(s3);
                if (len3 == 3 && strncmp(s3, "255", len3) > 0) {
                    continue;
                }
                len4 = strlen(s4);
                if (len4 == 3 && strncmp(s4, "255", len4) > 0) {
                    continue;
                } else if (len4 > 1 && s4[0] == '0') {
                    //剔除0xx开头的
                    continue;
                }

                printf("%s.%s.%s.%s\n", s1, s2, s3, s4);
                retStr[*returnSize] = malloc(srcLen + 3 + 1);
                strncpy(retStr[*returnSize], s1, len1);
                retStr[*returnSize][len1] = '.';
                strncpy(retStr[*returnSize] + len1 + 1, s2, len2);
                retStr[*returnSize][len1 + 1 + len2] = '.';
                strncpy(retStr[*returnSize] + len1 + 1 + len2 + 1, s3, len3);
                retStr[*returnSize][len1 + 1 + len2 + 1 + len3] = '.';
                strncpy(retStr[*returnSize] + len1 + 1 + len2 + 1 + len3 + 1, s4, len4);
                retStr[*returnSize][srcLen + 3] = '\0';
                *returnSize += 1;
            }
        }
    }
    
    return retStr;
}
```