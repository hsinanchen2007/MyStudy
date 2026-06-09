char * generateTheString(int n){
    int cnt, num;
    char *pret = (char *)malloc((n+1)*sizeof(char));
    memset(pret, 0, (n+1)*sizeof(char));
    // 分为偶数，还是奇数
    for (int i = 0; i < n; i++) {
        pret[i] = 'a';
    }    
    num = n % 2;
    if (num == 0) {
        pret[n - 1] = 'b';
    }
    
    return pret;
}
