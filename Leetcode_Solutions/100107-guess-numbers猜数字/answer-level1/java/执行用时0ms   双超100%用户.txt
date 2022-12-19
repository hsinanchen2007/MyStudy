```
class Solution {
    /**
     * 执行用时 :0 ms, 在所有 java 提交中击败了100.00%的用户
     * 内存消耗 :33.7 MB, 在所有 java 提交中击败了100.00%的用户
     * @param guess
     * @param answer
     * @return
     */
    public int game(int[] guess, int[] answer) {
        int count = 0;
        for (int i = 0; i < 3; i++) {
            if (guess[i] == answer[i]) count++;
        }
        return count;
    }
}
```
