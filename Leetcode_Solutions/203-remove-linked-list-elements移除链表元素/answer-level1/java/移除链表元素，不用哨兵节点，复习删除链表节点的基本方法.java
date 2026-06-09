要删除一个List中的节点，需要把该节点之后的所有元素向前移动一位，把它覆盖掉，最坏情况下需要O(n)的时间复杂度，而删除链表中的节点只需要把该结点的前一个元素指向该结点的后一个元素，时间复杂度是O(1)，这是我们使用链表的原因也是链表的特性，即增删快，查询慢。但是本题需要稍微注意的是，删除链表的第一个元素、删除链表的中间元素和删除链表末端的元素，处理方法略有不同，具体如下：
1. 删除链表的第一个元素
   因为是单向链表，初始状态下head指向第一个结点，我们只需要让head=head.next就删除了第一个结点
2. 删除链表的中间元素
   因为是单向链表，head如果往后遍历，前面的元素就找不回来了，所以首先把head拷贝一份，即

    ListNode newList = head;

    然后newList.next = newList.next.next;  这样就删除了链表中间的某个结点
3. 删除链表的末尾元素
    删除末尾元素就更简单了，当newList指向链表的末尾时，newList=null就可以了

最后不要忘记在做判断之前先判空，并且在开头做个特殊处理，排除掉输入数据是null的特殊情况，完整代码如下：
```
    public ListNode removeElements(ListNode head, int val) {
        ListNode newList = head;
        if (newList == null) {
            return null;
        }
        while (newList != null && newList.val == val) {
            head = head.next;
            newList = newList.next;
        }
        while (newList != null && newList.next != null) {
            while (newList.next != null && newList.next.val == val) {
                newList.next = newList.next.next;
            }
            newList = newList.next;
        }
        return head;
    }
```
