### 解题思路
`此题解参考于 @夕颜 的思路`
4人家庭连续座位，在只有10列的影院中，每一行最多安排2个，最大值就是2n，每一行能坐下4人家庭的位置只有3种情况：

1. 2-5的位置没有占据
2. 4-7的位置没有占据
3. 6-9的位置没有占据

有些同学可能就奇怪了，诶，你的第2种情况不是包括在1和3里面了吗，这不是重复了吗？

**其实不是。如果2-5被占据的是2,3座位，6-7被占据的是8,9座位，那么4-7是完全可以放下一个4人家庭。所以，我们需要分类讨论。**

首先把每一行被占据的座位收集起来，然后进行判断，每行有效valid初始最大值为2，采用先两边，后中间的思路（这个可以类似夹逼准则理解吧，我实在是找不到一个好理解的名词了）。

2-5如果有占据，valid-1。
6-9如果有占据，valid-1。

这时候，如果valid > 0，这表示有满足的条件的4人家庭座位，该行处理完毕。不用再特判4-7。

如果valid = 0了，则需要对4-7的位置进行一次特判。因为无法确定之前的情况是否有占据4-7。如果还有被占据，则该行无法放下任何一个4人家庭。如果没有被占据，则该行正好能放下一个4人家庭。

每一行重复以上判断，最终返回结果。

### 代码

```java
class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        // key 座位行 value 占据的作为
        Map<Integer, Set<Integer>> map = new HashMap<>();
        // 初始化
        for (int i = 0; i < reservedSeats.length; i++) {
            int[] reservedSeat = reservedSeats[i];
            Set<Integer> set = map.computeIfAbsent(reservedSeat[0], k -> new HashSet<>());
            set.add(reservedSeat[1]);
        }
        int res = n << 1;
        if (map.size() == 0) {
            return res;
        }
        for (Map.Entry<Integer, Set<Integer>> entry : map.entrySet()) {
            Set<Integer> set = entry.getValue();
            int valid = 2;
            // 2-5这一块的有效位置
            for (int i = 2; i <= 5; i++) {
                if (set.contains(i)) {
                    valid--;
                    break;
                }
            }

            // 6-9这一块的有效位置
            for (int i = 6; i <= 9; i++) {
                if (set.contains(i)) {
                    valid--;
                    break;
                }
            }

            if (valid == 0){
                // 之前两个区间都没有位置了，可能只是2-3和8-9占据了，对4-7再特判一次
                valid = 1;
                for (int i = 4; i <= 7; i++) {
                    if (set.contains(i)) {
                        valid--;
                        break;
                    }
                }
            }
            res -= 2 - valid;
        }
        return res;
    }
}
```