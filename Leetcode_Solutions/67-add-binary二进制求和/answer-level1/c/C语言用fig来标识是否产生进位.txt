char* addBinary(char* a, char* b) {
    int l1 = (int)strlen(a), l2 = (int)strlen(b);
    char* num = 0;
    int fig = 0,l1num=0,l2num=0,len = 0;

    len = l1 > l2 ? l1 : l2;
    num = (char*)malloc(sizeof(char) * (len + 2));//留一位用来进位
    num[len + 1] = '\0';

    for (; l1>=1||l2>=1; l1--,l2--,len--) {
        if (l1 >= 1)
            l1num = a[l1 - 1] - '0';
        else
            l1num = 0;
        
        if (l2 >= 1)
            l2num = b[l2 - 1] - '0';
        else
            l2num = 0;

        if (fig + l1num + l2num >= 2) {
            num[len] = (fig + l1num + l2num) % 2 + '0';
            fig = 1;
        }
        else {
            num[len] = (fig + l1num + l2num) % 2 + '0';
            fig = 0;
        }
    }

    if (fig == 1) { //进位还未消除
        num[0] = '1';
        return num;
    }
    else {
        return num + 1;
    }
}