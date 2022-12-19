```
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        if (seq.length() == 0) {
            return new int[]{};
        }
        int[] answer = new int[seq.length()];
        char[] chars = seq.toCharArray();
        int i = 0;
        int v = 0;
        while (i < chars.length) {
            if (chars[i] == '(') {
                answer[i] = v;
                v = 1 - v;
            } else {
                v = 1 - v;
                answer[i] = v;
            }
            i++;
        }
        return answer;
    }
}
```
