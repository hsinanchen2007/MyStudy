//为了避免溢出，使用字符串存储数据。
int reverse(int x){
    char * s = (char *) malloc(100 * sizeof(char));
    memset(s, 0, 100 * sizeof(char));
    int flag = 1;
    long xtemp;
    if(x < 0) {
        flag = -1;  
    }
    xtemp =(long) x * flag;
    int m = 0;
    while(xtemp > 0) {
        int value = xtemp % 10;
        xtemp = xtemp / 10;
        s[m++] = value;
    }
    int length = m - 1;
    long res = 0;
    for(int i = 0; i < m; i++) {
        res += (s[i]) * pow(10,length--);
    }
    
    if(flag == -1) {
        res = res * flag;
    }
    if((res > pow(2, 31) - 1) || res < -pow(2,31)) {
        return 0;
    }
    return res;
    
}

