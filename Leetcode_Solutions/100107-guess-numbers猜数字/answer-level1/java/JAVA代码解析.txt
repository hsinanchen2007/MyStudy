```
class Solution {
    public int game(int[] guess, int[] answer) {
        int times=0;/*这个用于计次我们的猜对记录*/
        for(int i=0;i<guess.length;i++){
        /*因为guess和answer的长度都是3.而且他们是根据下标对应来判断的。所以拿谁的长度都一样*/
        /* 如： [2,2,3]  */
        /*      [3,2,1]  */
        /* 下标为0时 2:3他们便不成立,下标为1时 2:2成立,下标为2时 3:1不成立*/
        if(guess[i]==answer[i]) times++;/*如果对应成功。就让 times+1*/
        }
        return times;
    }
}
```
