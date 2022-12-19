    int count = 0;
    char *a1 = malloc(sizeof(char) * 2);
    char *b1 = malloc(sizeof(char) * 2);
    int k = 0;
    int flag = 0;
    int cursor = 0;
    for (int i = 0; i < strlen(A); i++) {
        if (A[i] != B[i]) {
            a1[k] = A[i];
            b1[k] = B[i];
            if (k < 1) {
                k++;
            }
            count++;
        }
        if (flag == 0) {
            cursor = i;
            while (++cursor < strlen(A)) {
                if (A[i] == A[cursor]) {
                    flag = 1;
                    break;
                }
            }
        }
    }
    if ((a1[0] == b1[1]) && (a1[1] == b1[0]) && (count == 2)) {
        return 1;
    }
    if ((count == 0) && (flag == 1)) {
        return 1;
    }
    return 0;