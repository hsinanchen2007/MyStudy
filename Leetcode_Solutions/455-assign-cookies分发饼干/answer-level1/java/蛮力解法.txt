有点暴力，向别人学习，先满足小的，且分配的饼干刚好满足，在满足大的

### 代码

```java
class Solution {
    public int findContentChildren(int[] g, int[] s) {
      Arrays.sort(g);
      Arrays.sort(s);
      int i;
      int j,k=0;
      for(i = 0; i < g.length; i++)
         for(j = 0; j < s.length; j++){
             if(g[i]!=0){
                if(s[j]!=0)
                 if(g[i]<=s[j]){
                     g[i] = 0;
                     s[j] = 0;
                     k++;
                 }
             }
                
         }
    return k;

    }
}
```