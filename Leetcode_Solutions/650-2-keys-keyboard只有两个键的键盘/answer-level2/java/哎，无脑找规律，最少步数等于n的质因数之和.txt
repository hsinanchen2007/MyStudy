执行用时 :0 ms, 在所有 Java 提交中击败了100.00的用户内存消耗 :35.9 MB, 在所有 Java 提交中击败了13.21%
的用户

```
class Solution {
    public int minSteps(int n) {
        if(n==1) return 0;
            int m=0;
            int H=minC(n);
            while(H!=n)
            {
                m+=H;
                n=n/H;
                H=minC(n);
            }
            return m==0?n:m+H;
    }
    public int minC(int m)
    {
        for(int i=2;i<=m/2;i++)
        {
            if(m%i==0) return i;
        }
        return m;
    }
}
```
