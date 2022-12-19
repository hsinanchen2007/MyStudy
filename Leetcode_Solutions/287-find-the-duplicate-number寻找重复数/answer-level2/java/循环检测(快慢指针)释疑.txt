
## 一、为什么会产生循环链表？

n+1 个坑给 1~n 个数字，其中只有 1 个数字会重复出现。简称重复的数字为 dupl。因为
1. **只有** dupl 重复出现；
2. dupl 所占那两个坑的下标**不相等**，且属于 0~n，

所以从那两个坑的下标回溯源头，只能有两个结果（这里设 i 为链表地址，也就是数组下标。i 属于 0~n）：
1. 回溯到 i = 0。0 不属于 1~n ，链表中找不到它的前驱了，回溯结束，是为表头；
2. 回溯到 i 属于 1~n，总能找到它的前驱，形成闭环。

两个结果不可能在同一次回溯中出现，因为**只有** dupl 重复了，其他数字都没有重复，所以每个 dupl 各自认领其中的一个结果。所以必然会有一个循环链表产生，而且 dupl 是入口。

## 二、第一个 while 所寻找的是什么？

这里有两种情况。

第一种情况是乌龟指针进入了循环链表追上了野兔指针。两个指针指向了同一个节点（下标一样）。注意这不一定是入口，他们仅仅是在这个点相遇了而已。

第二种情况是乌龟指针没有进入循环列表，而循环列表内只有一个数字，即 dupl 本身。下面就第二种情况单独讨论。

在 @RockeyDon 的[回复](https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode/195021)中提到，交点一定是环上的点，但不一定是入口。这是第一种情况。还有一种情况是乌龟指针根本没有进入到循环链表，但由于循环只有 dupl 自己，导致结果依旧正确。

例子：[1,2,4,3,4]。

在野兔指针进入 nums[4] = 4 的循环时，乌龟指针还在 nums[2] = 4 处，根本没有进入循环。在循环链表的例子中，环上相交的点其下标/地址一定是相等的，但这里**不相等**。如果是因为这种情况进入第二个 while 的 case 就和下面第三点没有什么关系了，我们甚至可以优化代码让其就此结束运行，返回 dupl。经过这个优化你的执行时间就能战胜 100% 的用户了！

## 三、为什么第二个 while 中乌龟指针和野兔指针保持相同速度增长就能找到入口/dupl了？

抛开上一节提的特殊情况，龟兔指针在循环链表中相遇时可以列出下列等式。在此感谢  @maiff。

设从表头进入循环链表需要 a 步，两指针在循环列表中相遇距入口 x 步，循环链表长度为 b（尝试自己画张图）。

则在相遇时，

tortoise = a + x, hare = 2a + 2x

可列出 x = a + 2x - kb    (k>=1)

整理得 a = kb - x

可以看到只要再用一个指针 ptr1 从 nums[0] 开始向后走 a 步，另一个指针 ptr2 从相遇点向后走 a 或者也可以说 kb - x 步，它们就会再次相遇。不过这次不是因为闭环内龟兔竞速导致的相遇，而是按照我们计算好的在入口/dupl相遇。

```java
class Solution {
    public int findDuplicate(int[] nums) {
        int tor_index = 0;
        int hare_index = 0;
        int tortoise = nums[tor_index];
        int hare = nums[hare_index];
        do {
            tor_index = tortoise;
            hare_index = nums[hare];
            tortoise = nums[tor_index];
            hare = nums[hare_index];
        } while (tortoise != hare);
        if(tor_index != hare_index){
            return tortoise;
        }
        int ptr1 = tortoise;
        int ptr2 = nums[0];
        while(ptr1 != ptr2){
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }
        return ptr1;
    }
}
```