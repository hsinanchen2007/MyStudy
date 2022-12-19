for循环直接处理，好理解
char ** restoreIpAddresses(char * s, int* returnSize){
    int len = strlen(s);
    if (s == NULL || len < 4) {
        *returnSize = 0;
        return NULL;
    }
    
    char **res = (char **)malloc(sizeof(char *) * 5000);
    int i,j,k,m;
    char *tmp;
    char buf[4][4];
    
    *returnSize = 0;
    for (i = 1; i < 4; i++) {
        for (j = 1; j < 4; j++) {
            for (k = 1; k < 4; k++) {
                for (m = 1; m < 4; m++) {
                    if ((i + j + k + m) == len) {
                        memset(buf, 0, 4*4);
                        memcpy(buf[0], s, i);
                        memcpy(buf[1], s + i, j);
                        memcpy(buf[2], s + i + j, k);
                        memcpy(buf[3], s + i + j + k, m);

                        if ((atoi(buf[0]) > 255) || (atoi(buf[1]) > 255) || (atoi(buf[2]) > 255) || (atoi(buf[3]) > 255)) {
                            continue;
                        }

                        if (((strlen(buf[0]) > 1) && buf[0][0] == '0')
                            || ((strlen(buf[1]) > 1) && buf[1][0] == '0')
                            || ((strlen(buf[2]) > 1) && buf[2][0] == '0')
                            || ((strlen(buf[3]) > 1) && buf[3][0] == '0')) {
                            continue;
                        }

                        res[*returnSize] = (char *)malloc(len + 4);
                        tmp = res[*returnSize];
                        memcpy(tmp, s, i);
                        tmp += i;
                        tmp[0] = '.';
                        tmp++;
                        memcpy(tmp, s + i, j);
                        tmp += j;
                        tmp[0] = '.';
                        tmp++;
                        memcpy(tmp, s + i + j, k);
                        tmp += k;
                        tmp[0] = '.';
                        tmp++;
                        memcpy(tmp, s + i + j + k, m);
                        tmp += m;
                        tmp[0] = 0;
                        (*returnSize)++;                                                                      
                    }
                }
            }
        }
    }

    return res;
}