```
class Solution {
    public int heightChecker(int[] h) {
        // nlogn + n
        int[] a = new int[h.length];
        for(int i = 0; i < h.length; ++ i)
            a[i] = h[i];
        Arrays.sort(a);
        int rs = 0;
        for(int i = 0; i < h.length; ++ i)
            if(a[i] != h[i])
                rs ++;
        return rs;
    }
}
```
