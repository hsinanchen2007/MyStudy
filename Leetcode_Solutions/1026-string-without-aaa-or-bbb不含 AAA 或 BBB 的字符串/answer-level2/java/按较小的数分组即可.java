执行用时 :1 ms, 在所有 Java 提交中击败了99.64%的用户
内存消耗 :37 MB, 在所有 Java 提交中击败了5.29%的用户

```
class Solution {
    public String strWithout3a3b(int A, int B) {
        int min = Math.min(A, B);
        int max = Math.max(A, B);
        int div = max / (min + 1);
        int rd = max % (min + 1);
        char maxChar = max == A ? 'a' : 'b';
        char minChar = maxChar == 'a' ? 'b' : 'a';
        StringBuilder ans = new StringBuilder();
        for (int i=0; i<min; i++) {
            int number = i < rd ? div+1 : div;
            for (int j=0; j<number; j++)
                ans.append(maxChar);
            ans.append(minChar);
        }
        for (int i=0; i<div; i++)
            ans.append(maxChar);
        return ans.toString();
    }
}
```