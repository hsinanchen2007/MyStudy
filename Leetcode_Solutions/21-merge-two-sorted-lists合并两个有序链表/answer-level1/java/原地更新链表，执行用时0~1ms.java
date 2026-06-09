### 解题思路
![2.png](https://pic.leetcode-cn.com/eb35222bcad855d97af25e54b8f6f8c58c8066520306d89e1b1c1471121c5baa-2.png)

思路其实很简单，就是选择一条链表进行原地更新即可，遍历另一个链表，然后根据值的情况做出不同的处理。
时间复杂度 = O( min(len1, len2) )  空间复杂度 = O(1)
具体的步骤看代码注释吧
### 代码

```java
public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        // 对于任一链表为空的情况，直接判断即可
        if (l1 == null)
            return l2;
        if (l2 == null)
            return l1;
        // 记录l1上节点的前一个位置，方便插入
        ListNode pre1 = null;
        // 这个head是为了记录最新的头节点位置
        ListNode head = l1;

        while (l2 != null){
            // 在 l1 上找到一个符合 l2上节点插入的位置
            while (l1 != null && l1.val < l2.val){
                pre1 = l1;
                l1 = l1.next;
            }
            // 第一种情况，l1到尾了，说明l1上最大的元素都比当前l2上的节点小
            // 直接将 l2 挂在 l1的后面返回即可。
            if (l1 == null){
                pre1.next = l2;
                return head;
            }else if (pre1 != null){
                // 首先缓存l2的下一个节点
                ListNode tmp2 = l2.next;
                // 把当前l2节点插入
                pre1.next = l2;
                l2.next = l1;
                // 由于插入了一个数，所以前一个节点变为新插入的数，而l1上的当前点不需要改变
                pre1 = l2;
                // 移动l2到下一个点上
                l2 = tmp2;
            }else{
                // 这里表示pre为空也就是l1上的头节点都比l2当前点的值大的情况
                ListNode tmp2 = l2.next;
                // 把当前l2节点挂在头节点的前面
                l2.next = head;
                // 更新l2为最新的头节点
                head = l2;
                // 移动l2到下一个节点
                l2 = tmp2;
                // 移动l1到头节点位置
                l1 = head;
            }
        }
        return head;
    }
```