int binaryGap(int N){
    int res = 0;
    int flag = INT_MAX;
    for (int i = 0; i < 31; i++) {
        if ((N >> i) & 1) {
            res = res > (i - flag) ? res : (i - flag);
            flag = i;
        }
    }
    return res;
}