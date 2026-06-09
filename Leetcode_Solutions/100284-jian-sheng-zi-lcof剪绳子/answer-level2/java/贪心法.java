### 解题思路
1.但n小于等于3时继续分解只会令分解得到的乘积越来越小，所以分解到3就停止分解。
2.但n大于3时，求 n 除以 3 的 整数部分 a 和 余数部分 b （即 n =3a+b ）

### 代码

```java
class Solution {
    public int cuttingRope(int n) {
        if (n<=3){return n-1;}
        int a = n/3;
        int b = n%3;
        if(b==0) {
            return (int)Math.pow(3, a);
        }
        else if(b==1){
            return (int)(Math.pow(3,a-1)*4);
            }
        else{
            return (int)Math.pow(3,a)*2;
            }

    }
}
```