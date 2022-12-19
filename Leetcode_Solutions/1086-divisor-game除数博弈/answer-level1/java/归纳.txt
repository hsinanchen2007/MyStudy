这个应该是全网最简单的解法:

```
class Solution {
    public boolean divisorGame(int N) {
        /**
         * 在爱丽丝先开局的场景下
         * N 为奇数时, 结果一定为false
         * N 为偶数时, 结果一定为true
         */
        return N % 2 == 0;
    }
}
```
