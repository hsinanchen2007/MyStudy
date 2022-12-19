思路:
1. 使用数组存储每次要翻转的k个节点
2. 如果数组的长度等于k, 对数组中的节点进行翻转, 否则按原顺序输出
3. 数组中节点翻转步骤
 - 首节点链接至结尾的节点
 - 开头的节点链接至结尾节点的下一个节点
 - 数组中的节点从后往前依次链接
 - 重置首节点

```
private static ListNode reverse(ListNode head, int k) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode copy = dummy;
        ListNode[] listNodes = new ListNode[k];

        while (copy.next != null) {
            int i;
            ListNode temp = copy;
            //使用数组存储k个节点
            for (i = 0; i < k; i++) {
                listNodes[i] = copy.next;
                copy = copy.next;
                if (copy == null) {
                    break;
                }
            }

            if (i == k) {
                //首节点链接至结尾的节点
                temp.next = listNodes[k - 1];
                //开头的节点链接至结尾节点的下一个节点
                listNodes[0].next = listNodes[k - 1].next;
                //数组中的节点从后往前依次链接
                for (int j = k - 2; j >= 0; j--) {
                    listNodes[j + 1].next = listNodes[j];
                }
                //重置首节点
                copy = listNodes[0];
            }
            //剩余节点数不足k, 保持原有顺序
            else {
                break;
            }
        }

        return dummy.next;
    }
```
