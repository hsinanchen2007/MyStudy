### 解题思路
- n%10取模得到个位数
- n/10得到10位以前的数
### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
        int temp1 = 0;
        int temp2 = 1;
        while (n > 0) {
            int n1 = n%10;
            temp1+=n1;
            temp2*=n1;
            n=n/10;
        }
        return temp2-temp1;
    }
}
```