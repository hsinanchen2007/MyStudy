## 第一版
> 96ms,39M。时间复杂度O(2n)，空间复杂度O(1)。
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
 * @return {boolean}
 */
var isPalindrome = function(head) {
  if (!(head && head.next)) return true;
  let size = 1;
  let secondHalf = head;
  while (head.next) {
    head = head.next;
    size++;
  }
  let firstHalf = null;
  for (let i = 0; i < size / 2; i++) {
    let temp = secondHalf;
    secondHalf = secondHalf.next;
    temp.next = firstHalf;
    firstHalf = temp;
  }
  if (size % 2 === 1) firstHalf = firstHalf.next;
  while(secondHalf) {
    if (firstHalf.val !== secondHalf.val) return false;
    firstHalf = firstHalf.next;
    secondHalf = secondHalf.next;
  }
  return true;
};
```
## 思路：
1. 先遍历一次得到原链表的长度
2. 遍历原链表的一半，将前一半反转得到一个新链表
3. 遍历原链表剩下的一半，将每一项和新链表的每一项按顺序比较
4. 相当于总共遍历原链表2次

## 第二版，将第一版优化了一下
> 84ms,39.2M。时间复杂度O(3n/2)，空间复杂度O(1)。
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
 * @return {boolean}
 */
var isPalindrome = function(head) {
  if (!(head && head.next)) return true;
  let size = 1;
  let secondHalf = head;
  let firstHalf = null;

  while (head.next) {
    head = head.next;
    size++;
    if (size % 2 === 0) {
      let temp = secondHalf;
      secondHalf = secondHalf.next;
      temp.next = firstHalf;
      firstHalf = temp;
    }
  }
  if (size % 2 === 1) secondHalf = secondHalf.next;
  while(secondHalf) {
    if (firstHalf.val !== secondHalf.val) return false;
    firstHalf = firstHalf.next;
    secondHalf = secondHalf.next;
  }
  return true;
};
```
## 思路
1. 遍历一次原链表，一边计数，一边将链表的前一半反转（每当计数器为偶数时切割掉最前方的节点放到新链表的最前方）
2. 遍历剩下的一半链表，将新链表（即原链表前一半的反转）和原链表后一半每个节点的值按顺序比较
3. 和第一版相比总共只用遍历原链表1.5次

## 第三版，有点可惜不完全是自己独立想出来的，看了人家题解前两行才意识到还可以这样再优化。
> 84ms,39.2M。时间复杂度O(n)，空间复杂度O(1)。
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
 * @return {boolean}
 */
var isPalindrome = function(head) {
  if (!(head && head.next)) return true;
  let secondHalf = head;
  let firstHalf = null;

  while (head && head.next) {
    head = head.next.next;
    let temp = secondHalf;
    secondHalf = secondHalf.next;
    temp.next = firstHalf;
    firstHalf = temp;
  }
  if (head) secondHalf = secondHalf.next;
  while(secondHalf) {
    if (firstHalf.val !== secondHalf.val) return false;
    firstHalf = firstHalf.next;
    secondHalf = secondHalf.next;
  }
  return true;
};
```
## 思路：前两版的计数器根本可以不需要！第一部分迭代原链表时每次往后挪两位，同时反转前一位，时间复杂度O(n/2)。第二部分同第二版，时间复杂度也是O(n/2)。所以总的时间复杂度可以缩减到O(n)