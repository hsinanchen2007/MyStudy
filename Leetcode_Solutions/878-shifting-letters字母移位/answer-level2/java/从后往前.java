```
class Solution {
    private final char[] CC = new char[]{'a','b','c','d','e','f','g','h','i',
                                        'j','k','l','m','n','o','p','q',
                                        'r','s','t','u','v','w','x','y','z'};
    public String shiftingLetters(String S, int[] shifts) {
        char[] arr = S.toCharArray();
        int loop = 0;
        for (int i = shifts.length - 1;  i >= 0;  i--) {
            loop = (loop + shifts[i])%26;
            shift(arr, i, loop);
        }
        return new String(arr);
    }
    
    void shift(char[] arr, int idx, int loop) {
        int ori = arr[idx] - 'a';
        ori = (ori + loop) % 26;
        arr[idx] = CC[ori];
    }
}
```
执行用时 :3 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :40.6 MB, 在所有 Java 提交中击败了98.25%的用户
