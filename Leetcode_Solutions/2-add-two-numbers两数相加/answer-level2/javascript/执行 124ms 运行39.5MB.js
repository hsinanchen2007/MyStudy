### 解题思路
执行 124ms
运行39.5MB
1、初始一个listNode,以及保存一个最新节点currentNode，以及余数rem(每次相加更新，初始0)
2、while循环，计算l1 l2 rem相加后的个位数和十位数，保存到新的listNode、rem
3、currentNode.next指向新的listNode，然后更新currentNode值为最新的listNode
4、再更新l1 l2为他们的next值
5、直到退出循环
6、判断rem不为0则currentNode.next = new listNode(rem)
7、返回初始.next

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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let initList = new ListNode(null);
    let currentList = initList;
    let rem = 0;
    while (l1 != null || l2 !=null) {
        let num = (l1 ? l1.val : 0 ) + (l2 ? l2.val : 0) + rem;
        let nextList = new ListNode(num % 10);
        rem = Math.floor(num / 10);
        currentList.next = nextList;
        // 保存最新节点
        currentList = nextList;
        l1 = l1 ? l1.next : null;
        l2 = l2 ? l2.next : null;
    }
    if (rem) {
        currentList.next = new ListNode(rem);
    }
    return initList.next;
};
```