### 解题思路
    1、首先统计出每个数出现的次数，然后从小到大遍历每个数 i：
    2、如果 i 出现了两次以上，那么只留下1个，其他的count-1个数记录下来；
    3、如果 i 没有出现过，那么在记录下来的数中选取一个 j，将它增加到 j，需要进行的操作次数为 i - j。

### 代码

```java
class Solution {
    
    public int minIncrementForUnique(int[] A) {
       int[] count = new int[80000];
        for (int i : A) {
            count[i]++;
        }
        int cnt  = 0,move = 0;
        for (int i = 0; i < count.length; i++) {
            if(count[i] > 1){
                int d = count[i] - 1;
                move += d;
                cnt -= i*d;
            }else if(move > 0 && count[i] == 0){
                move--;
                cnt += i;
            }
        }
        return cnt;
    }
}
```