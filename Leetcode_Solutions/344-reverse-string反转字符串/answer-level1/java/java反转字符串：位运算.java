class Solution {
    public void reverseString(char[] s) {
        for (int i = 0; i < s.length / 2; i++) {
            int p = s.length - 1 - i;
            s[i] = (char) (s[i] ^ s[p]);
            s[p] = (char) (s[i] ^ s[p]);
            s[i] = (char) (s[i] ^ s[p]);
        }
    }
}

执行用时 :1 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :45.6 MB, 在所有 java 提交中击败了93.75%的用户