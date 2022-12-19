bool checkRecord(char *s) {
    int slen = strlen(s);
    int numA = 0;
    bool flag1 = true;
    bool flag2 = false;
    for (int i = 0; i < slen; i++) {
        if (s[i] == 'A') {
            numA++;
        } else if (s[i] == 'L') {
            int j = i;
            if ((s[j + 1] == 'L') && (s[j + 2] == 'L')) {
                flag1 = false;
                break;
            }
        } 
    }
    //printf("numA = %d\n",numA);
    //printf("numB = %d\n",numB);
    if (numA <= 1) flag2 = true;
    if (numA > 2) flag2 = false;
    return flag1&&flag2;
}
