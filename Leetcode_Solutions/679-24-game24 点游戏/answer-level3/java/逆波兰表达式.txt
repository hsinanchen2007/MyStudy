把全部运算情况的逆波兰表达式穷举出来, 如果存在一条表达式等于24.0返回true, 否则返回false.
24点的逆波兰表达式总共有如下4种情况. 其中abc的代表4个数字 #代表+-*/任意一个操作符.
ab#cd##
abc##d#
abcd###
ab#c#d#
采用逆波兰表达式是因为不用考虑操作符的优先级.
需注意的情况是除法运算, 除数为0时.

* 以下循环是4个数字的全排列, 4个数字不能重复使用(if判断, 过滤重复的情况).
``` java
for (int i1 = 0; i1 < 4; i1++) {
    for (int i2 = 0; i2 < 4; i2++) {
        if (i1 == i2) continue;
        for (int i3 = 0; i3 < 4; i3++) {
            if (i3 == i1 || i3 == i2) continue;
            int i4 = 6 - i1 - i2 - i3;
```
* 以下循环是操作符的全排列, 操作符可以重复使用.
```java
for (int o1 = 0; o1 < 4; o1++) {
    for (int o2 = 0; o2 < 4; o2++) {
        for (int o3 = 0; o3 < 4; o3++) {
```

* 完整代码
``` java
class Solution {
  public boolean judgePoint24(int[] nums) {
    float result = 0f, result1 = 0f;
    char[] operators = { '+', '-', '*', '/' };

    for (int i1 = 0; i1 < 4; i1++) {
      for (int i2 = 0; i2 < 4; i2++) {   if (i1 == i2) continue;
        for (int i3 = 0; i3 < 4; i3++) { if (i3 == i1 || i3 == i2) continue;
          int i4 = 6 - i1 - i2 - i3;

          for (int o1 = 0; o1 < 4; o1++) {
            for (int o2 = 0; o2 < 4; o2++) {
              for (int o3 = 0; o3 < 4; o3++) {
                // ab#cd##
                result = calculate(nums[i1], nums[i2], operators[o1]);
                result1 = calculate(nums[i3], nums[i4], operators[o2]);
                result = calculate(result, result1, operators[o3]);
                if (24.0 - result < 0.001 && result - 24.0 < 0.001) return true;
                // abc##d#
                result = calculate(nums[i2], nums[i3], operators[o1]);
                result = calculate(nums[i1], result, operators[o2]);
                result = calculate(result, nums[i4], operators[o3]);
                if (24.0 - result < 0.001 && result - 24.0 < 0.001) return true;
                // abcd###
                result = calculate(nums[i3], nums[i4], operators[o1]);
                result = calculate(nums[i2], result, operators[o2]);
                result = calculate(nums[i1], result, operators[o3]);
                if (24.0 - result < 0.001 && result - 24.0 < 0.001) return true;
                // ab#c#d#
                result = calculate(nums[i1], nums[i2], operators[o1]);
                result = calculate(result, nums[i3], operators[o2]);
                result = calculate(result, nums[i4], operators[o3]);
                if (24.0 - result < 0.001 && result - 24.0 < 0.001)return true;
              }
            }
          }
        }
      }
    }
    return false;
  }

    private float calculate(float a, float b, char operator) {
        switch (operator) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b == 0 ? -10 : a / b;
        default:  return -10;
        }
    }
}
```