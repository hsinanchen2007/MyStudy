```
bool isPerfectSquare(int num){
    bool flag = false;
    for(int i = 1; i<=num/i; i++){
        if(i*i == num){
            flag = true;
            break;
        }
    }
    return flag;
}
```