三层循环，基本思想，单个IP字段数字不超3个，剩余的IP字段至少保证有一个数字，依次轮巡。
如果找到的IP字段每个都小于255，且首数字不是0为合法，保存即可（最多81个）

#define OneIPLen 4
#define IPlen 16
#define IPMaxNum 81
void JudgeAndSave(char *ip1, char *ip2, char *ip3, char *ip4, char **rlt, int *returnSize)
{
    if (((ip1[0] == '0') && (strlen(ip1) != 1)) || ((ip2[0] == '0') && (strlen(ip2) != 1)) ||
        ((ip3[0] == '0') && (strlen(ip3) != 1)) || ((ip4[0] == '0') && (strlen(ip4) != 1))) {
        return;
    }

    if ((atoi(ip1) > 255) || (atoi(ip2) > 255) || (atoi(ip3) > 255) || (atoi(ip4) > 255)) {
        return;
    }

    rlt[*returnSize] = (char *)calloc(1, IPlen);
    sprintf(rlt[*returnSize], "%s.%s.%s.%s", ip1, ip2, ip3, ip4);
    (*returnSize)++;
}

char **restoreIpAddresses(char *s, int *returnSize)
{
    char ip1[OneIPLen], ip2[OneIPLen], ip3[OneIPLen], ip4[OneIPLen];
    int ip1Index, ip2Index, ip3Index, ip4Index, ipLen;
    char **rlt;
    // 参数检查和保护
    *returnSize = 0;
    if (s == NULL) {
        return NULL;
    }

    if ((strlen(s) < 4) || (strlen(s) > 12)) {
        return NULL;
    }

    rlt = (char **)malloc(sizeof(char *) * IPMaxNum);
    // 获取可能的IP组合

    ipLen = strlen(s);
    for (ip1Index = 0; ip1Index < ipLen - 3; ip1Index++) {
        // IP1字段最多3个数字
        if (ip1Index > 2) {
            continue;
        }
        for (ip2Index = ip1Index + 1; ip2Index < ipLen - 2; ip2Index++) {
            // IP2字段最多3个数字
            if ((ip2Index - ip1Index) > 3) {
                continue;
            }
            for (ip3Index = ip2Index + 1; ip3Index < ipLen - 1; ip3Index++) {
                // IP3字段最多3个数字
                if ((ip3Index - ip2Index) > 3) {
                    continue;
                }

                ip4Index = ip3Index + 1;
                if ((ipLen - ip4Index) > 3) {
                    continue;
                }

                memset(ip1, 0, OneIPLen);
                strncpy(ip1, s, ip1Index + 1);
                memset(ip2, 0, OneIPLen);
                strncpy(ip2, s + ip1Index + 1, ip2Index - ip1Index);
                memset(ip3, 0, OneIPLen);
                strncpy(ip3, s + ip2Index + 1, ip3Index - ip2Index);
                memset(ip4, 0, OneIPLen);
                strcpy(ip4, s + ip3Index + 1);

                JudgeAndSave(ip1, ip2, ip3, ip4, rlt, returnSize);
            }
        }
    }

    return rlt;
}