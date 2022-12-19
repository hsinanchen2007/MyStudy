### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int getSum(int a, int b) {
        int c = a ^ b;
        int d = (a & b) << 1;
        /* 第一步：异或
        第二步：计算进位值，按位与后左移一位
        第三步重复上述两步，直到进位值为0，。
        结束条件：进位为0，即a为最终的求和结果。*/
        while(d != 0){
            a = c;
            b = d;
            c = a ^ b;
            d = (a & b) << 1;
        }
        return c;
    }
}
```