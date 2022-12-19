### 解题思路
此处撰写解题思路

### 代码

```c
#define FIVEDOLLAR 0
#define TENDOLLAR 1
#define TWENTYDOLLAR 2

bool lemonadeChange(int* bills, int billsSize)
{
    if (!bills || billsSize <= 0) {
        return true;
    }
    int* wallet = (int*)malloc(sizeof(int) * 3);
    memset(wallet, 0, sizeof(int) * 3);
    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            wallet[FIVEDOLLAR]++;
            continue;
        }
        if (bills[i] == 10) {
            if (wallet[FIVEDOLLAR] > 0) {
                wallet[TENDOLLAR]++;
                wallet[FIVEDOLLAR]--;
                continue;
            } else {
                return false;
            }
        }
        if (bills[i] == 20) {
            if (wallet[TENDOLLAR] > 0 && wallet[FIVEDOLLAR] > 0) {
                wallet[TWENTYDOLLAR]++;
                wallet[TENDOLLAR]--;
                wallet[FIVEDOLLAR]--;
                continue;
            }
            if (wallet[FIVEDOLLAR] > 2) {
                wallet[TWENTYDOLLAR]++;
                wallet[FIVEDOLLAR] -= 3;
                continue;
            }
            return false;
        }
    }
    return true;
}
```