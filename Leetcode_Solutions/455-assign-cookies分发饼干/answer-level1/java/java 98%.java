
### 代码

```java
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int count=0;
        int sIndex=0;
        for(int gg : g){
            if(s.length-1>=sIndex){
                while(s[sIndex]<gg&&s.length-1>=sIndex+1){
                    sIndex++;
                }
                if(s[sIndex]>=gg){
                    count++;
                    sIndex++;
                }
            }
            
        }
        return count;
    }
}
```