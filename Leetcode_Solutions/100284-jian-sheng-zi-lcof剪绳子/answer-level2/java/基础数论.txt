### 解题思路
此处撰写解题思路
为了简化式子，直接当n为2的时候返回1，n为3的时候换回2，n为4的时候显然2X2大于1x3
当n大于4的时候有2^3 < 3^2，因此大于4的时候尽量让3多点
### 代码

```java
class Solution {
    public int cuttingRope(int n) {
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        int sum = 1;
        while(n > 4){
            sum *= 3;
            n -= 3;
        }
        return sum*n;
        
    }
}
```