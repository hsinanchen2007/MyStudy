为啥 我本地 ab， ab 输出false， 但是提交以后为true

```
class Solution {
    public boolean buddyStrings(String A, String B) {
        if (A == "" || B == "" || A == B || A.length() != B.length()) {
            return false;
        }

        char[] AA = A.toCharArray();
        char[] BB = B.toCharArray();
        
        Arrays.sort(AA);
        Arrays.sort(BB);

        for (int i=0; i<AA.length;i++) {
            if (AA[i] != BB[i]) {
                return false;
            }
        }
        return true;
    }
}
```