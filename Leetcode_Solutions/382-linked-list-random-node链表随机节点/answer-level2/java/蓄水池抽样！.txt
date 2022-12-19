### 解题思路
查阅了一些博客，谈谈蓄水池抽样！

我们先来谈一个抽奖问题。
假设有n张彩票，其中有一张彩票会中奖，每个人轮流走到彩票面前，抽取一张，每个人中奖的概率均等，均为1/n。
第一个人 彩票有n张 中奖的概率自然为1/n
第二个人 彩票有n-1张 中奖的情况为 第一个人没中奖（n-1/n）*自己中奖（1/n-1）= 1/n
...
所以每个人中奖的概率均为1 / n

类比到蓄水池抽样，我们从数据流（n）中随机选择一个元素，确保每个元素被选择的概率为 1 / n
当第一个元素出现时，我们选择它 概率为 1 / 1.
当第二个元素出现时，我们以 1 / 2 的概率（用随机数产生）选择它，概率为 1 / 2.

我们观察前两个元素，发现好像只有第二个元素符合要求，因为它是我们实实在在根据随机数产生并且满足 1/2 的概率选中的
那么第一个元素不满足吗？

其实不然，因为我们以 1/2 的概率选中第二个元素时（第一个元素必然未被选中），未被选中的概率为（1- 1/2），我们再乘以第一轮被选中的概率 1 / 1 结果也是 1 / 2.满足要求。

当第三个元素出现时，我们若以 1 / 3 的概率选中它，它是符合要求的 1 / n (此时n 为 3)。
那么此时第二个元素的选中符合要求吗？
为第二个元素必然未被选中的概率（1 - 1 / 3），因为第三个元素已经以1 / 3的概率选中了
（1 / 2） * （1 - 1 / 3） = 1 / 3，也满足要求。

代码比较简单，注意随机数的产生就好。


### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    
    private ListNode head;

    /** @param head The linked list's head.
    Note that the head is guaranteed to be not null, so it contains at least one node. */
    public Solution(ListNode head) {
        this.head = head;
    }

    /** Returns a random node's value. */
    public int getRandom() {
        //以1的概率选择该元素head
        ListNode current = head;
        ListNode temp = head.next;
        int len = 2;
        while (temp != null){
            //以1/len的概率选择元素temp
            //从1，2，3，4，5...len 中随机选择一个元素
            //random()产生的是[0,1)的double型的数
            int target = 1 + (int) (Math.random() * len);
            if (target == len)
                current = temp;
            temp = temp.next;
            len++;
        }
        return current.val;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
```