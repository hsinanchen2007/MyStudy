### 解题思路
思想就避免递归的重复计算，我们将计算的值用中间数保存起来就可以了。复杂度O(n)，还有更快的O(logn)比较麻烦就不写了

### 代码

```java
class Solution {
    public int fib(int n) {
        int[] res={0,1};
        if(n<2)return n;
        int fb1=1;
        int fb2=0;
        int item=0;
        for (int i=2;i<=n;i++){
            item=(fb1+fb2)%1000000007;
            fb2=fb1;
            fb1=item;
        }
        return item;
    }
}
```