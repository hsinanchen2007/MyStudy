### 解题思路
1. 需要考虑正负号，故采用long（带正负号）
2. rNum为每一次操作后的数，从一位到N位，*10 为下一位腾出个位
3. 随后强制转换int，如果溢出int范围，则显示溢出特征，与long不相等

### 代码

```c
int reverse(int x){
    long rNum = 0;
    while(x != 0){
        rNum = rNum * 10 + x % 10;
        x = x / 10;
    }
    if((int) rNum != rNum) return 0;
    return rNum;
}
```