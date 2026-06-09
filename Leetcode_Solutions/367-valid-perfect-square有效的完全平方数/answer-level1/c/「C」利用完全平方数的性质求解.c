### 解题思路

完全平方数可以通过累加从1往后的奇数找到，

 1 = 1;
 4 = 1 + 3;
 9 = 1 + 3 + 5;
16  = 1 + 3 + 5 + 7;
...

计算过程只需要加减法，效率极高。

```c
bool isPerfectSquare(int num){
    if (num == 0 ) return false;

    int i = 1;
    while ( num > 0){
        num -= i;
        i += 2;
    }
    return num == 0 ? true : false;

}
```