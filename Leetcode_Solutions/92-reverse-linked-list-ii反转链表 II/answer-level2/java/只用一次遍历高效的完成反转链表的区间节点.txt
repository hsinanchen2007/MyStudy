**具体思路看代码注释哦～～：**


```
    /** 
     * 一次遍历高效完成反转链表的区间节点，解题思路如下：<br>
     *     1. 首先，检查边界情况；<br>
     *     2. 在遍历过程中，找到区间链表反转后的整体的前驱节点con和后继节点tail；<br>
     *     3. 接着，如果遍历到的节点属于区间内的节点，则直接反转指针指向。这里要注意边界值：不包含第m个节点，包含第n个节点；<br>
     *     4. 接着，后移整个链表的指针：前驱节点prev和当前节点curr；<br>
     *     5. 最后，当遍历到第n个节点时，链接起来首尾节点，再处理一下此时当m=1时，头节点要指向prev节点。<br>
     *     6. 一共用到了5个指针和1个索引。
     */
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (head == null) {
            return null;
        }
        if (m == 0 || n == 0 || m >= n) {
            return head;
        }

        ListNode prev = null, curr = head, next = null;
        // 区间链表反转后的前驱节点，当m=1时，con为null（不存在这个前驱节点）
        ListNode con = null;
        // 区间链表反转后的后继节点
        ListNode tail = null;

        int index = 0;
        while (curr != null) {
            if (++index == m) {
                con = prev;
                tail = curr;
            }

            next = curr.next;
            // 反转区间内的节点
            if (m < index && index <= n) {
                curr.next = prev;
            }
            // 后移下面两个指针
            prev = curr;
            curr = next;

            if (index == n) {
                if (con != null) {
                    // 连接区间节点的前驱节点
                    con.next = prev;
                } else {
                    // 当m=1时，头节点设置为prev
                    head = prev;
                }
                // 连接区间节点的后继节点
                tail.next = curr;
            }
        }
        return head;
    }
```
