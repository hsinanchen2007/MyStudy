## 第一版，递归。构建一个新的链表，使用递归给新的链表添加节点，添加完成后将新链表返回
> 116ms,36.1M。
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
var reverseList = function(head, pre = null) {
  if (!head) return null;
  if (head.next === null) return { val: head.val, next: pre };
  return reverseList(head.next, { val: head.val, next: pre });
};
```

## 第二版，迭代。迭代构建一个新链表返回
> 88ms,35.7M
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
var reverseList = function(head) {
  if (!head) return null;
  let revChain = { val: head.val, next: null };
  for (let cur = head.next; cur; cur = cur.next) {
    revChain = { val: cur.val, next: revChain };
  }
  return revChain;
};
```

---
### 看了官方题解之后。。。

## 第三版，还是迭代，也是构建新链表，但比我的第二版更简化一些
> 76ms,34.9M。
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
var reverseList = function(head) {
  let pre = null;
  for (let cur = head; cur;) {
    let nextTemp = cur.next;
    cur.next = pre;
    pre = cur;
    cur = nextTemp;
  }
  return pre;
};
```

## 第四版，还是递归，操作比较风骚
> 76ms,35.2M
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
var reverseList = function(head) {
  // console.log('a', head);
  if (!(head && head.next)) return head;
  const p = reverseList(head.next);
  // console.log('b', head, '-------', p);
  head.next.next = head;
  // console.log('c', head, '-------', p);
  head.next = null;
  // console.log('d', head, '-------', p);
  return p;
};
```
## 分析：
1. 感觉官方题解的递归确实有点难理解，将每一行的的执行结果都打印出来我才看出来到底做了什么操作。
    + 优点：相当于将原链表中的节点从后向前一个一个拆下来并按顺序放入新链表，原链表从后往前每拆一个节点，新链表p的尾部就加上这个被拆下的节点。
    + 缺点：
      1. 没有尾递归优化，链表节点数量大递归很深的情况下存在溢出危险
      2. 方法直接修改内存地址的指向，操作不直观。思路很好，但代码可读性较差（可能我太菜所以一下看不出来）
2. 具体步骤分析：
    1. `const p = reverseList(head.next);`这一行代码中的p对于整个递归栈而言最终返回了原链表中最后一个节点的地址，也是反转后新链表的head
    2. `head.next.next = head;`这一行做的操作比较复杂。
        1. 递归每次退栈后时head相当于从后往前迭代原链表的每一个节点
        2. 实际上head.next已经是原链表的当前尾节点了，在递归上一次退栈过程中的`head.next = null;`已经将当前递归栈中head.next.next变为null。
        3. 同时head.next即原链表的当前尾节点和新链表p的尾节点是指向同一个内存地址的，也就是新旧链表的尾部此时在内存中是同一个地址。
        4. 看出来以上三点之后，可以得到`head.next.next = head;`同时也是**p[尾节点].next = head**，就是将当前节点head的地址添加到新链表p的尾部。这个操作将原链表的第n个节点放到了第n+1个节点的后面，所以仍然存在一点问题，就是循环引用。
    3. `head.next = null;`因为上一行执行完后实际上使 **head.next** 和 **head.next.next** 变成了循环引用，所以需要将这个循环给释放掉，不然新链表的尾部也是一个存在相同的循环引用。因为此时的 **head.next === p[在循环引用之前的末尾节点]** (同时 head === p[在循环引用之前的末尾节点].next)，即 **head.next** 和 **p[在循环引用之前的末尾节点]** 是指向同一个内存地址。所以这一行的操作就是在切断循环引用，切完之后实际上已经实现了当前末位节点的反转
    4. `return p;`每次递归退栈返回尾部添加了一个新节点的反转后链表
