### 红黑树的解题思路
两个花盆间隔K个花盆，则两者的编号差的绝对值要为K+1。

**核心思想**
利用红黑树的有序性，维护**已经开花**的花盆集合。

1.新开花的花盆index，要找前后分别距离自己最近的两个花盆low和high。low和high是小端和大端最靠近index的花盆，中间不会再有别的花盆。
2.只要index-low == K + 1，就满足low和index两个开花花盆之间刚好有K个花盆没开花。high的判断同理，改为high-index == K + 1即可。

这个解法的时间复杂度是O(Nlog(N))，空间复杂度O(N)。并不是最优解，但是比较容易想到。以后再更新新的，更高效的题解。

### 代码

```java
class Solution {
    public int kEmptySlots(int[] bulbs, int K) {
        // 间隔K个花盆，则两者的差要是K+1
        // 开花的花盆编号
        TreeSet<Integer> slotSet = new TreeSet<>();
        for (int i = 0; i < bulbs.length; i++) {
            // 编号小于当前花盆的开花花盆
            Integer low = slotSet.lower(bulbs[i]);
            if (low != null && bulbs[i] - low == K + 1){
                return i + 1;// 满足条件的天
            }
            // 编号大于当前花盆开花的花盆
            Integer high = slotSet.higher(bulbs[i]);
            if (high != null && high - bulbs[i] == K + 1){
                return i + 1;// 满足条件的天
            }
            slotSet.add(bulbs[i]);// 当前花盆加入
        }
        return -1;
    }
}
```