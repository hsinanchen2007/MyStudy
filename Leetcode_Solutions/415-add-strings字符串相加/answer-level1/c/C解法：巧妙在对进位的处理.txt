char * addStrings(char * num1, char * num2){
    int i = strlen(num1); //2
    int j = strlen(num2); //0
    int sum = 0;
    char *temp = (char *)malloc(5100);
    int k = 0, t = 0;
    int tx = 0;
    // 从后往前加，进位保留
    while (i > 0 || j > 0 || tx > 0) {
        if (i > 0 && j > 0) sum = num1[i - 1] - '0' + tx + num2[j - 1] - '0';
        else if (i > 0) sum = num1[i - 1] - '0' + tx;
        else if (j > 0) sum = num2[j - 1] - '0' + tx;
        else sum = tx;
        tx = sum / 10;
        // printf("tx = %d, %d\n",tx, sum % 10);
        temp[k]  = sum % 10 + '0';
        --i;
        --j;
        ++k;
     } 
    //for(int i = 0; i < k; i++) {
    //    printf("%d\n",temp[i]);
    //}
    // 前后对调
    for(int i = 0; i < k/2; i++) {
        t = temp[i];
        temp[i] = temp[k-i-1] ;
        temp[k-i-1] = t;
    }
    temp[k] = 0;
    return temp;

}