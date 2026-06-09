### 解题思路
解法：

- 方法一：将值复制到数组中后用双指针法
- 方法二：快慢指针法，快指针走两步，慢指针走一步，找到链表的中点。然后，翻转后半部分。最后从头、中点开始判断是否相同

### 代码

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * 方法一：将值复制到数组中后用双指针法;
 * 时间复杂度O(n)，空间复杂度O(n)
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
  let vals = [];
  while (head) {
    vals.push(head.val);
    head = head.next;
  }
  // 数组双指针首尾一起遍历，数组访问元素复杂度是O(1)
  let len = vals.length - 1;
  let s = 0;
  while (len >= s) {
    if (vals[s] !== vals[len]) {
      return false;
    }
    len--;
    s++;
  }
  return true;
};
```

**解法二：快慢指针法**

```js
/**
 * 方法二：快慢指针法
 * 时间复杂度O(n)，空间复杂度O(1)
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
  // 得到链表中间结点slow
  let slow = head;
  let fast = head;
  while (fast && fast.next) {
    slow = slow.next;
    fast = fast.next.next;
  }

  // 反转中间结点开始的后半链表
  let prev = null;
  while (slow) {
    let next = slow.next;
    slow.next = prev;
    prev = slow;
    slow = next;
  }

  // 对比链表前半部分和反转后的后半部分
  while (prev && head) {
    if (head.val !== prev.val) {
      return false;
    }
    prev = prev.next;
    head = head.next;
  }

  return true;
};
```


## More


关于链表数据结构笔记：[https://github.com/giscafer/leetcode-js/tree/master/src/data-structures/linked-list](https://github.com/giscafer/leetcode-js/tree/master/src/data-structures/linked-list)

![fe-insights.jpg](https://pic.leetcode-cn.com/936dcb02e5f5636a779abf809514677985a18b20667952e608527e2026f1c3a2-fe-insights.jpg)
