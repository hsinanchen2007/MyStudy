因为题目要求的返回时String[]，这时候灵活变通下，不用List动态扩容，而是计算下数组容量，然后填充。
```java
class Solution {
    String[] res = null;
    public String[] permutation(String S) {
        int size = 1;
        char[] chars = S.toCharArray();
        for(int i = 1; i <= chars.length; i++) {
            size *= i;
        }
        res = new String[size];
        helper(chars, new int[]{0}, 0);
        return res;
    }

    public void helper(char[] chars, int[] i, int index) {
        if(index == chars.length - 1) {
            res[i[0]++] = new String(chars);
            return;        
        }

        for(int j = index; j < chars.length; j++) {
            exch(chars, index, j);
            helper(chars, i, index + 1);
            exch(chars, index, j);            
        }
    }

    public void exch(char[] chars, int i, int j) {
        char c = chars[i];
        chars[i] = chars[j];
        chars[j] = c;
    }
}
```