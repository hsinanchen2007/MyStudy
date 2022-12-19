```
char *convert(char *str, int numRows) {
    if (strlen(str) == 0) {
        char *result = (char *) malloc(sizeof(char));
        result[0] = '\0';
        return result;
    }
    char temp[numRows][strlen(str) + 1];
    char *result = (char *) malloc(sizeof(char) * (strlen(str) + 1));
    result[strlen(str)] = '\0';
    int fig1 = 0;
    int num[numRows];
    for (int i = 0; i < numRows; ++i) {
        num[i] = 0;
        temp[i][0] = '\0';
    }

    int update = 1;

    for (int i = 0; i < strlen(str); i++) {
        int row = fig1 % numRows;
        temp[row][num[row]] = str[i];
        temp[row][num[row] + 1] = '\0';
        num[row]++;
        if (fig1 == 0) {
            update = 1;
        } else if (fig1 == numRows - 1) {
            update = -1;
        }
        fig1 += update;
    }

    fig1 = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < strlen(temp[i]); ++j) {
            result[fig1++] = temp[i][j];
        }
    }

    return result;
}
```
