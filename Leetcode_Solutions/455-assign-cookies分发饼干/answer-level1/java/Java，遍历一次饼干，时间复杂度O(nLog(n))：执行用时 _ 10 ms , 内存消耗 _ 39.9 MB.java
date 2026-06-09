想法：让胃口小的孩子吃饱，胃口大的就饿着吧

```
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int j = 0;
        for (int i : s) {
            if (i >= g[j]){
                j++;
                if (j >= g.length){
                    return j;
                }
            }
        }
        return j;
    }
}
```