时间复杂度O(n)，空间复杂度O(1)的解法：

```
class Solution {
    public int game(int[] guess, int[] answer) {
        //边界判断
        if (guess.length != 3 || answer.length != 3) return 0;
        int res = 0;
        for (int i = 0; i < 3; i++){
            //猜测结果判断
            if(guess[i] == answer[i]) {
                res = res + 1;
            }
        }
        return res;
    }
}
```

问题：有没有更优的解法？
