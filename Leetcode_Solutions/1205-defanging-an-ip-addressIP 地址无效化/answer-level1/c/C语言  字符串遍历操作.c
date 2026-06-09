char * defangIPaddr(char * address){
    int len = (int)strlen(address);
    int invalidLen = len + 10;

    char *invalidAdd;
    invalidAdd = (char *)malloc(invalidLen);

    int i = 0;
    int j = 0;
    for (; i < len && j < invalidLen; i++, j++) {
        if (address[i] == '.') {
            invalidAdd[j] = '[';
            invalidAdd[j + 1] = '.';
            invalidAdd[j + 2] = ']';
            j = j + 2;
        } else {
            invalidAdd[j] = address[i];
        }
    }
    invalidAdd[j] = '\0';
    return invalidAdd;

}
