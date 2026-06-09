### 解题思路
**方法一**：位运算，初始化cur = head,num = 0;每遍历一个结点执行num += cur,然后将num向左移动一位
时间复杂度：O(n)
空间复杂度：O(1)

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
 * @return {number}
 */
var getDecimalValue = function(head) {
    //  位运算
    let cur = head;
    let num = 0;
    while(cur != null){
        num <<= 1;
        num += cur.val;
        cur = cur.next;
    }
    return num;
};
```

**方法二**：遍历两遍，第一遍计算链表长度
时间复杂度：O(n)
空间复杂度：O(1)

### 代码

```javascript
var getDecimalValue = function(head) {
    let dummyNode = new ListNode(0);
    let cur1 = dummyNode,cur2 = dummyNode;
    dummyNode.next = head;
    let num = 0;
    let listLen = 0;
    while(cur1.next !== null){
        listLen++;
        cur1 = cur1.next;
    }
    
    while(cur2.next != null){
        listLen--;
        num += Math.pow(2,listLen) * cur2.next.val;
        cur2 = cur2.next;
    }
    return num;
};

```


**方法三**：反转链表，遍历一遍链表（代码略）
