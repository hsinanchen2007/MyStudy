java 击败 100%

```
class Solution {
    public int findLucky(int[] arr) {
        int[] aa = new int[500];
        for (int i=0; i<aa.length; i++) {
            for (int k: arr) {
                if (i == k) {
                    aa[i]++;
                }
            }
        }

        for (int i=aa.length-1; i>0; i--) {
            if (aa[i] == i) {
                return i;
            }
        }
        return -1;
    }
}
```