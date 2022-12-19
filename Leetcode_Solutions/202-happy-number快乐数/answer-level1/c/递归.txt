```

bool happy(int n, int * num) {
    int value;
    int res = 0;
    while(n > 0) {
        value = n % 10;
        n = n / 10;
        res += pow(value, 2);
    }
    (*num)++;
    if(res == 1 ) {
        return true;
    }
    if(*num == 1000) {
        return false;
    }
    return happy(res, num);
}

bool isHappy(int n){
    int num = 0;
    return happy(n, &num);
}


```
