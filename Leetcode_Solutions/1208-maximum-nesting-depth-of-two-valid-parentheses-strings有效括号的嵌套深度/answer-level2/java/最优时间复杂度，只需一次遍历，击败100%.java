### 解题思路
规律：(((( ))))的编码是0101 1010，可见遇到“(”只需要0、1交替即可，遇到“)”只需要0、1互换，然后交替即可。

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int[]ans=new int[seq.length()];
        int now=0;
        char[]c=seq.toCharArray();
        for(int i=0;i<ans.length;i++)
        {
            if(c[i]=='(')
            {
                ans[i]=now;
                now=1-now;
            }
            else if(c[i]==')')
            {
                ans[i]=1-now;
                now=1-now;
            }
        }
        return ans;
    }
}
```