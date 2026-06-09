```
class Solution {
    public int[] diStringMatch(String S) {
         int n = S.length();
        int[] a = new int[n + 1];
        int l = 0;
        int r = n;
        for (int i = 0; i < n; i++) {
            if (S.charAt(i) == 'I') {
                a[i] = l++;
            } else {
                a[i] = r--;
            }
        }
        a[n] = l;
        return a;
    }
}
```
