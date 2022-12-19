### 解题思路
n%10取出每次n/10后的n的个位数，就是最开始的n的各个数位上的数字，直到n为0时停止循环。

### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
        int he = 0;
        int ji = 1;
        while(n>0){
            he+=n%10;
            ji*=n%10;
            n/=10;
        }
        return ji-he;
    }
}
```