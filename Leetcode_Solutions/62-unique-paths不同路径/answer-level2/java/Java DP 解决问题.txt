参考这位大神的代码和思路, 我修改了一部分

```
class Solution {
    public int uniquePaths(int m, int n) {

        double dom = 1;
        double dedom = 1;
        int small = Math.min(m-1,n-1);
        int big = Math.max(n-1,m-1);
        for (int i = 1; i<=small; i++)
        {
            dedom *= i;
            dom *= small+big+1-i;
        }
        return (int)(dom/dedom);
    }
}
```
