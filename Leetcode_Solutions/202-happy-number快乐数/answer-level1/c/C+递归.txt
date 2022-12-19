### 解题思路
1、找规律：所有的输入整数，经过几轮递归后都会小于10；
小于10的整数中只有1和7是快乐数；
即采用递归算法，递归截止条件：若输入为1和7，则返回TRUE；若是其它小于10的数字，则返回FALSE。
2、计算平方和：采用迭代的方法将整数的个、十、百位分割为一个个数字进行平方和；

### 代码

```c
bool isHappy(int n){
    int yuShu, nextNum;
    if ((n == 1) || (n == 7)) {
        return true;
    } else if (n < 10) {
        return false;
    }
    nextNum = 0;
    while (n != 0) {
        yuShu = n % 10;
        nextNum += yuShu * yuShu;
        n = n / 10;
    }

    return isHappy(nextNum);
}
```