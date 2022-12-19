### 解题思路
此处撰写解题思路

### 代码

```c
bool lemonadeChange(int* bills, int billsSize) {
    int billKind[3] = {0,0,0};
    if(bills[0] == 10 || bills[0] == 20) {
        return false;
    }

    for (int i =0; i < billsSize; i++) {
        if (bills[i] == 5) {
            billKind[0]++;
        } else if (bills[i] == 10) {
            if (billKind[0] > 0) {
                billKind[0] --;
                billKind[1] ++;
            } else {
                return false;
            }
        } else if (bills[i] == 20) {
            if(billKind[1] > 0 && billKind[0] > 0) {
                billKind[0] --;
                billKind[1] --;
                billKind[2] ++;                  
            } else if (billKind[0] > 3) {
                billKind[0] = billKind[0] - 3;
                billKind[2] ++;
            } else {
                return false;
            }
        }
    }
    return true;
}
```