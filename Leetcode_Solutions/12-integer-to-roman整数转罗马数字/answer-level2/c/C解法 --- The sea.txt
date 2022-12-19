#define MAXLEN 16

char * intToRoman(int num){
    int mInt[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *mChar[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    char *ret = NULL;
    int idx = 0;
    int bak = num;

    ret = (char *)malloc(MAXLEN);
    if (ret == NULL) {
        return NULL;
    }
    memset(ret, '\0', MAXLEN);

    while (idx < sizeof(mInt) / sizeof(int)) {
        while (bak >= mInt[idx]) {
            strcat(ret, mChar[idx]);
            bak -= mInt[idx];
        }
        idx++;
    }

    return ret;
}
