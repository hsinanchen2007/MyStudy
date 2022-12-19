### 解题思路
链表交换两个节点，第一二次提交失败是因为没有考虑边界情况，即只有头结点（包括头结点为空）的情况。
本地尝试时，第一次输入[1,2,3,4]返回值却为[2,1,3],自己模拟下考虑应该是两两节点虽然交换成功，但是没有考虑前后衔接的问题。故写了个辅助函数，增加一个before参数记录上一个节点，保证衔接上下两个子链
![image.png](https://pic.leetcode-cn.com/5735d8c2fb1f798e6cbd8d6419619ec92247c1890259a13ac9a031d2be54faac-image.png)

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
var swapPairs = function(head) {
    return help(head, null)
    function help(head, before) {
        if (head === null || head.next === null) return head
        let temp = head
        head = head.next
        temp.next = head.next
        head.next = temp
        if (before) {
            before.next = head
        }
        help(temp.next, temp)
        return head
    }
    
};
```