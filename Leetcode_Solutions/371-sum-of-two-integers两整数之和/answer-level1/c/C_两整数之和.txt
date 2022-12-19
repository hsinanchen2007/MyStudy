### 解题思路
位操作法
sum=a^b+(a&b)<<1
参考1 https://www.jianshu.com/p/157cc4c12181
参考2 https://leetcode-cn.com/problems/sum-of-two-integers/solution/cwei-yun-suan-by-tuyeeee/

### 代码

```c
int getSum(int a, int b){
    int sum = a ^ b;
    unsigned carry = (unsigned) (a&b)<<1;
    return carry ? getSum(sum,carry) : sum;
}
```