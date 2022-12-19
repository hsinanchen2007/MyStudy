class Solution {
    public int game(int[] guess, int[] answer) {
        int num = 0;
        for(int i = 0; i < 3; i++) {
            if(guess[i] == answer[i]) {
                num++;
            }
        }
        return num;
    }
}
没啥弯弯绕，直接循环对比

![WX20190927-004246@2x.png](https://pic.leetcode-cn.com/8e5de9e07e76c1cd4c0a3fbe233ae01bd9d72ecd995e103c62ff25beac3ce2cf-WX20190927-004246@2x.png)
