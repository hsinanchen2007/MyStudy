### 解题思路
建立两个变量分别更新

### 代码

```java
class Solution {
    public int fib(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        int add1 = 0, add2 = 1;
        int ans = 0;
        for(int i = 2; i <= n; i++){
            ans = (add1 + add2) % 1000000007;
            add1 = add2;
            add2 = ans;
        }
        return ans;
    }
}
```