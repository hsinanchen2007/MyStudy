![image.png](https://pic.leetcode-cn.com/bd816e5db070c28e4700a3f2814663212af1f1d5a389ffe94f6ec1419b727956-image.png)
![image.png](https://pic.leetcode-cn.com/ed792fd7d2d2b5e12837ae90369a73014e4dfa44904608a56129beff70e904bc-image.png)


### 解题思路
###### 第一种就不说了，遍历链表，奇数索引的节点连成一个新的链表，偶数索引的节点连成一个新的链表，拼接两个链表
###### 第二种：原地算法：类似于插入排序
拿题目的例子来举例`1->2->3->4->5->NULL`
注意：题目中的说明并不影响我们解题，我们可以把第一个节点视为偶数索引节点来解题【按题目要求当做奇数也可以哈，只不过0为开始的索引我已经习惯了，我就这样来想了，算法都是一样的】，那就把所有的偶数索引节点连到一起，把所有的奇数索引节点自然就连到一起了。
思路：
1. 处理边界情况，如果链表长度不到 3 的话，不需要处理，直接返回链表
2. 把第一个节点当做已连接好的偶数索引链表的最后一个节点，遍历链表，遍历偶数索引的节点，把所有的偶数节点插入到已排好的偶数索引链表的最后一个节点之后
3. 插入排序的过程
- 初始化四个指针:
- 当前已排好的偶数索引链表的最后一个节点 order
- 当前已排好的偶数索引链表的最后一个节点的下一个节点 next
- 当前排序的下一个偶数索引的节点 curr
- 当前排序的下一个偶数索引的节点的下一个奇数索引节点 nextSingle
4. 整个过程的终止条件：curr的下一个奇数节点为null 或者 curr的下一个偶数节点为null

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
 * @return {ListNode}
 */
var oddEvenList = function(head) {
  if (!head || !head.next || !head.next.next) return head;
  
  let order = head,
      next = order.next,
      curr = next.next;
  
  while (curr) {
    let nextSingle = curr.next;
    curr.next = order.next;
    next.next = nextSingle;
    order.next = curr;
    
    if (!nextSingle || !nextSingle.next) break;
    order = order.next;
    curr = nextSingle.next;
    next = nextSingle;
  }
  
  return head;
};
```