### 解题思路
这是一个斐波那契模型
n=0时，没有跳法，即只有一种选择
n=1时，有一种选择
n=2时，可以先跳大第一阶上，然后跳到第二阶上，也可以直接跳到第二阶上。即有两种选择
n>2时，可以从（n-1）上跳过来，也可以从（n_2）上跳过来

### 代码

```java
class Solution {
    public int numWays(int n) {
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return 1;
        }
        long f_0 = 1;
        long f_1 = 1;
        long f_2 = 0;
        for(int i=2;i<=n;i++){
        f_2 = (f_0 + f_1)%1000000007;
        f_0 = f_1;
        f_1 = f_2;
        }
        return (int)f_2;

    }
}
```