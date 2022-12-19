### 解题思路
递归解法，每次都先判断是否有K长度，没有直接返回，有的话翻转K个，后面的递归调用。
可以优化为每次只进行一次循环

### 代码

```javascript
/*
 * @lc app=leetcode.cn id=25 lang=javascript
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
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
    let cursor 
    for (let index = 0; index < k; index++) {
        if (cursor === undefined) {
            cursor = head
        } else if (cursor) {
            cursor = cursor.next
        } else {
            cursor = false;
        }
    }
    if (cursor) {
        let newLink = reverseKGroup(cursor.next, k);
        let oriHead = head;
        for (let index = 0; index < k; index++) {
            const currHead = {val: oriHead.val}
            currHead.next = newLink;
            newLink = currHead;

            oriHead = oriHead.next
        }   
        return newLink;
    } else {
        return head;
    }

};
// @lc code=end


```