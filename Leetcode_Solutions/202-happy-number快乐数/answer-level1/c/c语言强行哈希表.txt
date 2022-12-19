bool isHappy(int n){
    int num[10000] = {0}; //这里设置10000的原因是n要非常多位才有可能超过这个数
    int sum = 0;
    while (1) {
        while (n != 0) {
            sum = sum + (n%10) * (n%10);
            n = n/10;
        }
        if(num[sum] == 1) 
            return (sum == 1) ;
        else
            num[sum] = 1;
        n = sum;
        sum = 0;
    }
}

