```
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int[] res = new int[seq.length()];
        int left = 0;
        for (int i = 0; i < seq.length(); i++) {
            if (seq.charAt(i) == '(') {
                left++;
                res[i] = left % 2 == 1? 0: 1;
            } else {
                left--;
                res[i] = left % 2 == 1? 1: 0;
            }
        }
        return res;
    }
}
```
