**递归**
```
bool isUgly(int num){
    if (num < 1) return false;
    return judge(num);
}
int judge(int num) {
    int ret = 0;
    if (num == 1) return 1;
    if (num % 2 == 0)         ret = judge(num / 2);
    if (!ret && num % 3 == 0) ret = judge(num / 3);
    if (!ret && num % 5 == 0) ret = judge(num / 5);

    return ret;
}
```
**非递归**
```
bool isUgly(int num) {
    if (num < 1) return false;
    while (num!=1) {
        if      (num % 2 == 0) num /= 2;
        else if (num % 3 == 0) num /= 3;
        else if (num % 5 == 0) num /= 5;
        else                return false;
    }
    return true;
}
```




