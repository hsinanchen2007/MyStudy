![image.png](https://pic.leetcode-cn.com/b2dc5974f3930c838302654126bc44576ac24c9ee92e0c09e2fb47c355980ac5-image.png)

### 解题思路
在head前面加一个值为 null 的头结点，从头遍历链表
下面是循环的思路
1. 设定三个指针
- curr：当前节点
- prev：上一个节点
- next：下一个节点
- p：额外指针，用来保存每次 k个一组的链表 翻转之前的头结点
2. 遍历链表并翻转过程的终止条件是 `curr === null`
- 每次初始化 `count = k`
- 先从当前节点向后数一下是否还有 k 个有效节点
- headcount：计数；temp：临时节点，保存的是当前节点的指针 curr
- 如果不足 k 个节点，直接连上不足 k 个节点的链表，跳出循环即可
- 如果够 k 个节点，那么走后面的 while 循环进行翻转
3. 翻转的过程：
- 用 next 保存当前节点的下一个节点的指针
- 把当前节点的下一个节点指向 prev
- prev 指针后移
- curr 指针后移
4. 每翻转一组之后的逻辑
- 保存p节点的下一个节点 pnext ，反转之后，它会成为下一组即将处理的链表的前一个节点
- p节点指向反转之后的头结点
- p节点挪到刚才保存的 pnext 指针的位置，此时的 pnext 为上一组链表翻转过后的尾节点，也是下一组即将处理的链表的前一个节点
- p节点的 next 指向 curr
- 继续循环即可
##### 建议大家画图理解一下，个人觉得还挺绕的，😋

### 代码

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */

var reverseKGroup = function(head, k) {
  let newHead = new ListNode( null ); // 返回的新链表
  newHead.next = head;
  let p = newHead; // 新链表的指针
  let prev = null,
      curr = head,
      next = null,
      count = k;
  while (curr !== null) {
    count = k;
    
    let headcount = 0, temp = curr;
    while (temp !== null) {
      temp = temp.next;
      headcount++;
    }
    if (headcount < k) break;
    
    while (count-- > 0 && curr !== null) {
      next = curr.next;
      curr.next = prev;
      prev = curr;
      curr = next;
    }
    
    let pnext = p.next;
    p.next = prev;
    p = pnext;
    p.next = curr;
  }
  
  return newHead.next;
}

```