int check(char *src) {

    int len = strlen(src);
    if (len == 0 || len > 3) {
        return 1;
    }

    switch (len) {
        case 1:
            break;
        case 2:
            if (src[0] == '0') {
                return 1;
            }
            break;
        case 3:
            if (src[0] <= '0' || src[0] > '2') {
                return 1;
            }

            if (src[0] == '2' && src[1] > '5') {
                return 1;
            }

            if (src[0] == '2' && src[1] == '5' && src[2] > '5') {
                return 1;
            }
    }

    return 0;
}

char ** restoreIpAddresses(char * s, int* returnSize){


    int slen = strlen(s);
    char temp1[4] = {0};
    char temp2[4] = {0};
    char temp3[4] = {0};
    char temp4[4] = {0};

    char **output = (char **)malloc(1024*sizeof(char *));

    int number=0;
    for (int i = 0; i <= 2; i++) {
        for (int j = i + 1; j <= i + 3; j++) {
            for (int z = j +1; z <= j + 3 && z < slen - 1; z++) {
                if (slen - 1 - z > 3) {
                    continue;
                }
                memset(temp1, 0, 4);
                memset(temp2, 0, 4);
                memset(temp3, 0, 4);
                memset(temp4, 0, 4);

                strncpy(temp1, &s[0], i+1);
                if (check(temp1) != 0) {
                    continue;
                }
 
                strncpy(temp2, &s[i + 1], j - i);
                if (check(temp2) != 0) {
                    continue;
                }

                strncpy(temp3, &s[j + 1], z - j);
                if (check(temp3) != 0) {
                    continue;
                }

                strncpy(temp4, &s[z + 1], slen -1 -z);
                if (check(temp4) != 0) {
                    continue;
                }

                output[number] = (char *)malloc(20);
                memset(output[number], 0, 20);
                sprintf(output[number], "%s.%s.%s.%s", temp1, temp2, temp3, temp4);
                number++;
            }
        }
    }

    *returnSize = number;
    return output;
}