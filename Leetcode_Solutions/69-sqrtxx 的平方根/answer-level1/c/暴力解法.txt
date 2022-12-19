```


int mySqrt(int x){
    if(x == 1) {
        return 1;
    }
    if(x == 0) {
        return 0;
    }
    int num = x / 2;
    for(int i = 1; i <= num; i++) {
        if(pow(i,2) <= x && pow(i + 1, 2) > x) {
            return i;
        }
    }
    return 0;
}


```
