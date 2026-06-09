### 解题思路
    // (a * b) % c = (a % c)(b % c) % c
    // 2 ^ 23 = 2 ^ 2 ^ 10 * 2 ^ 3

### 代码

```java
class Solution {


    public int pow(int x, int n){
        if(n == 0)
            return 1;
        if(n == 1)
            return x % 1337;
        return pow(x % 1337, n / 2) * pow(x % 1337, n - n / 2) % 1337;
    }

    public int superPow(int a, int[] b) {
        
        int res = 1;

        for(int i = 0; i < b.length; i++){
            res = pow(res, 10) * pow(a, b[i]) % 1337;
        }
        return res;
    }
}
```