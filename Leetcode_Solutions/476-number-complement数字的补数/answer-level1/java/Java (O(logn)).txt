### 解题思路
举例: num = 5 ==> 0101, 0101 ^ 0111 = 0010 ==> result
所以，我们进行补数运算的时候，只要找到和num有相同二进制位数，且所有位都为1的数temp, 让temp ^ num即是答案。

### 代码

```java
class Solution {
    // 举例: num = 5 ==> 0101, 0101 ^ 0111 = 0010 ==> result
    // 所以，我们进行补数运算的时候，只要找到和num有相同二进制位数，且所有位都为1的数temp, 让temp ^ num即是答案。
    public int findComplement(int num) {
        int temp = 1;
        while(temp < num){
            temp *= 2;
            temp++;
        }
        return temp ^ num;
    }
}
```