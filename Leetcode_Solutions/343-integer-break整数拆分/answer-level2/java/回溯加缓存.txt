### 解题思路
回溯加缓存，说明可以动态规划，想了很久都没有想到，我太笨了

### 代码

```java
class Solution {
    private int Max;
    private int[] cache;
    private int _Work(int n){
        if(this.cache[n]!=0)
            return this.cache[n];
        int Max=0,tmp=0;
        if(n<0)
            return -1;
        if(n==0)
            return 1;
        for(int i=1;i<=n;i++){
            tmp=_Work(n-i)*i;
            if(tmp<0)
                continue;
            if(Max<tmp)
                Max=tmp;
        }
        this.cache[n]=Max;
        return Max;
    }
    public int integerBreak(int n) {
        int tmp=0;
        this.Max=0;
        this.cache=new int[n+1];
        for(int i=1;i<n;i++){
            tmp=_Work(n-i)*i;
            if(this.Max<tmp)
                this.Max=tmp;
        }
        return this.Max;
    }
}
```