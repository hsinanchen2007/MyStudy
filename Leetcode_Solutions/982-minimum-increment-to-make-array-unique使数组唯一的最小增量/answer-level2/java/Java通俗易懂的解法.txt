# 解题思路

首先定义一个count数组用于保存数组A中元素出现的次数。ans为增量。
根据题意，count数组中每个位置的值最多只能为1。当count[x] >= 2时，总是希望后面有count = 0的位置来放置其多出来的元素。所以将多出来的count[x] - 1个元素先加到x + 1的位置上（后面总会有count为0的位置）;ans随之增加count[x] - 1。

```
class Solution {
    public int minIncrementForUnique(int[] A) {
        int[] count = new int[80000];
        for (int a : A) {
            count[a]++;
        }

        int ans = 0;
        for (int x = 0;x < 80000;x++) {
            if (count[x] >= 2) {
                ans += count[x] - 1;
                count[x + 1] += count[x] - 1;
            }
        }
        return ans;
    }
}
```
