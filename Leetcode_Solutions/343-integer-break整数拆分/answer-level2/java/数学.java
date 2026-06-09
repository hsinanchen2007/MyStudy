### 解题思路
这题不知道咋做，看别人的解题方式才知道的。
2 = 1 * 1 = 1
3 = 1 * 2 = 2
4 = 2 * 2 = 4
5 = 2 * 3 = 6
可以看到3就是不要在分的数字了。再往下分就会变少。所以都分解到3，乘积就都是最大的了。
具体的证明方式也可以通过数学方式证明。这里就不搬运别人的成果了。

### 代码

```java
class Solution {
    public int integerBreak(int n) {

        if(n <= 3)
            return n - 1;
        int x = (int)n / 3;

        if(n % 3 == 0){
            return (int)Math.pow(3, x);
        }
        else if(n % 3 == 1){
            return 4 * (int)Math.pow(3, x - 1);
        }
        else{
            return 2 * (int)Math.pow(3, x);
        }
    }
}
```