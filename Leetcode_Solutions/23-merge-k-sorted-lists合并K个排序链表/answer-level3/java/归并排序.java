### 分析
对于[1->4->5, 1->3->4, 2->6] 三个头节点分别为 1，1，6，
我们将第一个链表的头结点1放入结果res，此时变为[4->5, 1->3->4, 2->6]   res 1
我们是如何找出第一个1的呢，其实就是将 1 ，1，2三个数进行比较。得出最小的数为1。
还存在一个问题，这个最小的1在哪个链表呢？因为将其加入res后，此链表要向右移一位，
次数可以维护一个变量minPos来记录最小的数在哪个链表。
现在将第二个链表的头结点1放入结果res，此时变为[4->5, 3->4, 2->6]   res 1->1
将第三个链表的头结点2放入结果res，此时变为[4->5, 3->4, 6]   res 1->1->2
将第二个链表的头结点3放入结果res，此时变为[4->5, 4, 6]   res 1->1->2->3
将第一个链表的头结点4放入结果res，此时变为[5, 4, 6]   res 1->1->2->3->4
将第二个链表的头结点4放入结果res，此时变为[5,    6]   res 1->1->2->3->4->4
注意此时第二个链表为null了，为了让第二个链表不参与下一轮的比较，
我们可以引入 boolean[] tmp = new boolean[lists.length]，表示此链表是否已经为null。
最后再将5和6加入res，还存在一个问题，怎么判断已经全部加入res了呢？可以引入一个变量cntTmp，
每当一个链表变为null的时候cntTmp++，那么cntTmp == lists.size就表示全部数据已经处理完。
此种方法效率不高，时间复杂度O(nk),但是很容易想到，也很能锻炼代码能力。
### 代码
````java
public ListNode mergeKLists(ListNode[] lists) {

        ListNode res = new ListNode(-1);
        if (lists == null || lists.length == 0) {
            return res.next;
        }
        //表示此链表是否已经全加上去
        boolean[] tmp = new boolean[lists.length];
        int min = Integer.MAX_VALUE;
        //记录本轮的最小值在哪个地方
        int minPos = -1;
        //已经遍历完成的链表的数量
        int cntTmp = 0;

        ListNode head = res;

        while (cntTmp < lists.length) {
            for (int i = 0; i < lists.length; i++) {
                //第i条链表还未全部加上去
                if (!tmp[i]) {
                    //第i条链表已经到了null，说明已经全部加上去了
                    if (lists[i] == null) {
                        tmp[i] = true;
                        cntTmp++;
                        continue;
                    }
                    if (min > lists[i].val) {
                        min = lists[i].val;
                        minPos = i;
                    }

                }
            }
            if (min != Integer.MAX_VALUE) {
                res.next = lists[minPos];
                res = res.next;
                lists[minPos] = lists[minPos].next;
                min = Integer.MAX_VALUE;

            }


        }
        return head.next;
    }
````
### 优化
可以模仿归并排序的思想，先分再合。时间复杂度为O(n∗log(k))
### 代码
```java
public ListNode mergeKLists1(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        return merge(lists, 0, lists.length - 1);
    }

    private ListNode merge(ListNode[] lists, int left, int right) {
        if (left == right) {
            return lists[left];
        }
        int mid = left + (right - left) / 2;
        ListNode node1 = merge(lists, left, mid);
        ListNode node2 = merge(lists, mid + 1, right);
        return merge(node1, node2);
    }

    private ListNode merge(ListNode node1, ListNode node2) {
        if (node1 == null || node2 == null) {
            return node1 == null ? node2 : node1;
        }
        if (node1.val < node2.val) {
            node1.next = merge(node1.next, node2);
            return node1;
        } else {
            node2.next = merge(node1, node2.next);
            return node2;
        }

    }
```
本人建了个公众号用于刷题交流，欢迎关注：
![qrcode_for_gh_8eedbc428c9a_258(1).jpg](https://pic.leetcode-cn.com/e5f794b173fbe256a541447fc7ff8e6eb031774890bdfdb48ca3c7866dc81dc2-qrcode_for_gh_8eedbc428c9a_258\(1\).jpg)