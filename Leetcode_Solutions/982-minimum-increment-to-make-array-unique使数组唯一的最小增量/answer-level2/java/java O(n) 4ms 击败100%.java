
官方题解没有看懂。
我的方法，找到最大值，根据最大值创建数组。数组中存放数字出现的次数。
数字 i 的次数大于1的，找到后续最近的一个空位 cur，move次数就是 cur - i
cur 大于数组长度后，不用再找，直接+1

```
class Solution {
    public int minIncrementForUnique(int[] A) {
        if(A == null || A.length == 0) return 0;
        int max = 0;
        for(int i = 0; i < A.length; i++) {
            max = Math.max(max, A[i]);
        }
        int[] counts = new int[max + 1];
        for(int i = 0; i < A.length; i++) {
            counts[A[i]] += 1;
        }
        int cur = 0;
        int move = 0;
        for(int i = 0; i < counts.length; i++) {
            while(counts[i] > 1) {
                counts[i] -= 1;
                if(cur < i) cur = i + 1;
                if(cur < counts.length) {
                    while(cur < counts.length && counts[cur] > 0) cur++; 
                }
                move += (cur - i);
                cur++;
            } 
        }
        return move;
    }
}
```
