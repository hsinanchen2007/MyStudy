Java提交记录：【node = node.next在该题为何不正确】
- 删除 (100%,67%)

```java
class Solution {
    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
/**【理解】这里的输入node相当于一个指针，指向原链表中某节点的一个地址，相当于一个副本
 *  node = node.next只是修改了node的地址（指向下一个节点），只改变了node的指向（即只修改了副本），未改变原链表。
 *  只有将node所指当前地址对应的val和next修改才实现了删除（其实是替换）。
 *  例如有链表[4,5,1,9]，node = 5->      
 *  node=node.next
 *  只是把node指向了1这个节点，但是4这个节点的next依旧指向了5，所以5这个要求被删除的节点并没有被覆盖或者删除。
 */
```



