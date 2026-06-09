### 解题思路
优先使用 10元而不是5元，完美的诠释了贪心算法的精髓！！！！！

### 代码

```c
bool lemonadeChange(int* bills, int billsSize){
    int five = 0;
    int ten = 0;
    int tewnty = 0;
    int i;
    for (i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            five++;
        } else if (bills[i] == 10) {
            ten++;
            five--;
        } else {
            tewnty++;
            if (ten == 0) {
               five--;
               five--; 
            } else {
                ten--;
            }
            five--;  
        }
        if (five < 0 || ten < 0) {
            return false;
        }
    }
    return true;
}
```