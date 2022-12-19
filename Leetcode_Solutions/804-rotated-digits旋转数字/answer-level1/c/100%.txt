### 解题思路
此处撰写解题思路

### 代码

```c
bool isBelongToGoodNum(int num, int* flag)
{
    bool result;
    if (num == 2 || num == 5 || num == 6 || num == 9) {
        *flag = 0;
        result = true;
    } else if (num == 1 || num == 8 || num == 0) {
        result = true;
    } else {
        result = false;
    }
    return result;
}

bool isGoodNum(int number)
{
    int yushu = 0;
    int flag = 1;
    while(number/10 != 0) {
        yushu = number % 10;
        if (isBelongToGoodNum(yushu, &flag)) {
            number = number / 10;
        } else {
            return false;
        }
    }
    yushu = number % 10;
    if (isBelongToGoodNum(yushu, &flag) == false) {
        return false;
    }
    if (flag == 0) {
        return true;
    } else {
        return false;
    }
}

int rotatedDigits(int N){
    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (isGoodNum(i) == true) {
            result++;
        }
    }
    return result;
}
```