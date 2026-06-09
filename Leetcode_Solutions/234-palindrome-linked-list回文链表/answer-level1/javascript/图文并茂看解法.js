
### 解题思路

此题有两种解法，一是转化成数组，采用[数组的回文数](https://leetcode-cn.com/problems/palindrome-number/)的方法解, 另外一种是在链表的基础上解，本文仅解释第二种方法。

用人类的思维去解这道题，回文数嘛，我们很自然而然可以想到，可以找到它的中间点，然后从中间向两边进行对比。
那么，怎么去找到中间点呢，可以采用快慢指针快速迭代的方法。
![image.gif](https://pic.leetcode-cn.com/3315dfd314ffbdf18c4361de919e7b0eba83499878ec3401e3cc5b9908f047d6-image.gif)

先把快指针指向头指针的下一个节点，图片上方是链表长度为奇数的情况，在这个情况下`fast = null`的时候退出循环，下方是链表长度为偶数的情况，此时`fast.next = null`的时候退出循环。
由图可知，慢指针的下一个节点就是右边链表的起点，再运用快慢指针的方法将右边链表反转，因为右边反转链表比左边链表长，以右边链表长度为界，就口以解决这个问题啦～

### 代码

```javascript
var isPalindrome = function (head) {
    if (head === null || head.next === null) {
        return true;
    }
    let odd = head;
    let even = head.next;
    while(even !== null && even.next !== null) {
        odd = odd.next;
        even = even.next.next;
    }
    let startNode = odd.next;
    let restReverseNode = reverseNode(startNode);
    while(restReverseNode !== null) {
        if (head.val !== restReverseNode.val) {
            return false;
        }
        restReverseNode = restReverseNode.next;
        head = head.next;
    }
    return true;
}

let reverseNode = function(head) {
    let pre = head;
    let node = head.next;
    let curHead = pre;
    while(node !== null) {
        let tempNode = node;
        node = node.next;
        pre.next = node;
        tempNode.next = curHead;
        curHead = tempNode;
    }
    return curHead;
}


```