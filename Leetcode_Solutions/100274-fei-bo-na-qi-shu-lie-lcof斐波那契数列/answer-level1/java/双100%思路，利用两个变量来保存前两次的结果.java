### 解题思路
双100%思路，利用两个变量来保存前两次的结果

### 代码

```java
class Solution {
    public int fib(int n) {
        int[] res={0,1};
        if (n<2){
            return res[n];
        }
        int temp1=0;
        int temp2=1;
        int result=0;
        for (int i = 2; i <= n; i++) {
            result=temp1+temp2;
            result=result%1000000007;
            temp1=temp2;
            temp2=result;
        }
        return result;
    }
}
```