
char * addBinary(char * a, char * b){
    int i = strlen(a); //2
    int j = strlen(b); //0
    int sum = 0;
    char *temp = (char *)malloc(100);
    int k = 0, t = 0;
    int tx = 0;
    // 从后往前加，进位保留
    while (i > 0 || j > 0 || tx > 0) {
        if (i > 0 && j > 0) sum = a[i - 1] - '0' + tx + b[j - 1] - '0';
        else if (i > 0) sum = a[i - 1] - '0' + tx;
        else if (j > 0) sum = b[j - 1] - '0' + tx;
        else sum = tx;
        tx = sum / 2;
        temp[k]  = sum % 2+ '0';
        --i;
        --j;
        ++k;
     } 
    for(int i = 0; i < k/2; i++) {
        t = temp[i];
        temp[i] = temp[k-i-1] ;
        temp[k-i-1] = t;
    }
    temp[k] = 0;
    return temp;
}