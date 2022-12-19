第一个元素数值必须事5,  剩下的元素 如果是10 判断5美元的个数是否大于0   如果是10 判断是否有10 和 5  或者 5 5 5 

```
bool lemonadeChange(int* bills, int billsSize){
    if (bills[0] != 5) {
        return false;
    }
    int fiveCount = 1;
    int tenCount = 0;
    // int twentyCount = 0;
    for (int i = 1; i < billsSize; i++) {
        if (bills[i] == 5) {
            fiveCount++;
        }
        if (bills[i] == 10) {
            tenCount++;
            if (fiveCount > 0) {
                fiveCount--;
            } else {
                return false;
            }
        }
        if (bills[i] == 20) {
            if (tenCount > 0 && fiveCount > 0) {
                tenCount--;
                fiveCount--;
            } else if (fiveCount >= 3) {
                fiveCount -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}
```
