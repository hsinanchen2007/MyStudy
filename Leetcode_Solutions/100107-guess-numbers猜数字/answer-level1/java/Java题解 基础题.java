```
class Solution {
    public int game(int[] guess, int[] answer) {
        // 声明变量存储猜对的次数
        int rc = 0;
        // 直接循环即可
        for(int i=0;i<guess.length;i++){
            if(guess[i]==answer[i]){
                rc++;
            }
        }
        return rc;
    }
}
```
