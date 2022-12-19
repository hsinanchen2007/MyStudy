int a[4096] = {0};
bool isHappy(int n){
    int total = 0;
    while(n){
        total += ((n % 10)*(n % 10));
        n /= 10;
    }
    if(total == 1){
     for(int i=0; i<4096; i++)
         a[i] = 0;
        return true;
    }
    if(a[total] != 0)
        return false;
    a[total] = total;
    return isHappy(total);
}

看到题解区还没C的题解，提交一篇简易的C题解。