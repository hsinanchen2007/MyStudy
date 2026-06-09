## 第一版：双指针
> 60ms,36MB
```javascript []
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var oddEvenList = function(head) {
  if (!(head && head.next)) return head;
  
  const head2 = head.next;
  let node1 = head;
  head.next = null;
  let node2 = head2;

  while (node2) {
    let node2Next = node2.next;
    node2.next && (node2.next = node2.next.next);

    node1.next = node2Next;
    if(node1.next) {
      node1.next.next = null;
      node1 = node1.next;
    }
    node2 = node2.next;
  }
  node1.next = head2;
  return head;
};
```
### 思路
1. 将原链表分为两个链表，`head`作为奇数节点组成的链表头，`node1`作为`head`中的指针；`head2`作为偶数节点组成的链表头，`node2`作为`head2`中的指针
2. `head`初始只有原链表的第一个节点，`head2`初始为原链表第一个节点后的所有节点
3. 将`head2`中是原始链表中奇数节点的节点依次找出并切割出来，接入到`head`链表的尾部
4. `head2`链表中所有是原始链表中奇数节点的节点切割完后，再将`head2`接入`head`链表的尾部

#### 第一次提交直接成功超越100%了 o(*￣▽￣*)o