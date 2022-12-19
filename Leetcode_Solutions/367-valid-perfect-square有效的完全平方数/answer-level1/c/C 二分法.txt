### 解题思路
注意边界条件。

### 代码

```c
bool isPerfectSquare(int num){
    printf("%d,%d,%d",sizeof(short),sizeof(int),sizeof(long long));

    long left  = 0;
    long right = num;
    long tmp = 0;
    bool flag = false;
    if ((num == 0) || (num == 1)) {
        return true;
    }
    while(left < right) {
        //printf("%d,%d\r\n",left, right);
        tmp = (left + right + 1) / 2;
        if (tmp * tmp == num) {
            flag = true;
            break;
        } else if (tmp * tmp < num) {
            left = tmp;
        } else {
            right = tmp -1;
        }

    }

    return flag;
}
```