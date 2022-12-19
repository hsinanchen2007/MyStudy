### 解题思路
见批注

### 代码

```c
int divide(int dividend, int divisor){
    int flag = 1;
    if (dividend == 0) {
        return 0;
    }
    // 判定符号
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
        flag = -1;
    }
    // 统一转负数防止溢出
    if (dividend > 0) {
       dividend = -dividend;
    }
    // 统一转负数防止溢出
    if (divisor > 0) {
        divisor = -divisor;
    }
    // 剪枝，除数大直接返回0
    if (dividend > divisor) {
       return 0;
    }
    // 剪枝，最大最小整数除数为1时，根据符号直接返回
    if (dividend == INT_MIN + 1) {
        if (divisor == -1) {
            return flag == 1 ? INT_MAX : INT_MIN + 1;
        }
    }
    // 剪枝，最大最小整数除数为1时，根据符号直接返回
    if (dividend == INT_MIN) {
        if (divisor == -1) {
            return flag == 1 ? INT_MAX : INT_MIN;
        }
    }
    // 参考大神们的思路翻倍加值和计数
    int temp = divisor;
    int cnt = 1;
    while (dividend - temp <= temp) {
        if (INT_MIN - temp < temp) {
            temp += temp;
            cnt += cnt;
        } else {
            break;
        }
    }
    // 对剩余无法翻倍的部分进行计算
    dividend -= temp;
    while (dividend <= divisor) {
        dividend -= divisor;
        cnt++;
    }
    return flag == 1 ? cnt : -cnt;
}
```