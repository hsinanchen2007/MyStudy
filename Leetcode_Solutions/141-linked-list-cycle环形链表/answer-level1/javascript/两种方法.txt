## 第一版，哈希表
> 96ms,37.6M。空间复杂度O(n)
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
var hasCycle = function(head) {
  const nodeCollection = new Map();
  while(head) {
    if (nodeCollection.get(head)) return true;
    nodeCollection.set(head, 1)
    head = head.next;
  }
  return false;
};
```
## 第二版，双指针
> 88ms,36.5M。空间复杂度O(1)
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
var hasCycle = function(head) {
  let first = head;
  let second = head;
  while(first && first.next) {
    first = first.next.next;
    second = second.next;
    if (first === second) return true;
  }
  return false;
};
```
## 思路：
+ 双指针相当于速度不同的两名运动员在一个单向跑道上赛跑
  - 如果跑道没有环，那么速度快的肯定会先到终点停下来
  - 如果跑道存在环，那么他们一定会在某一时刻相遇

### 时间复杂度为O(n)，n为链表非循环部分的节点数，具体分析过程：
> 有一条由许多方格组成的跑道，跑道其中一部分是环状，两人单位时间内分别移动 **v1** 和 **v2** 个方格（每次至少移动整数个方格的距离），两人在在同一方格起跑，但起点不一定在环中，环的长度为 **p** 个方格，**跑道起点（相当于链表起点）** 到 **环的起点（相当于链表尾连接到链表中的位置）** 的距离为 **pos** 个方格，链表非循环部分的长度为 **S = p + pos** 个方格。问两人起跑后第一次进入同一个方格 **最多** 需要多长时间？

![image.png](https://pic.leetcode-cn.com/e972a23e47f2ed4ce70b7779a11906306c1c3cb7749cc5c71c04cf5550407ad7-image.png)

解：设人2比人1的速度快，即v2 > v1 > 0
1. 从起跑到两人都进入环需要的时间 t1 = pos / v1
2. 两人都进入环的时候相距的方格数 s1 = pos / (v2 - v1)
3. 快的人追上慢的人需要追及的距离 s2 = (p - s1 % p)
4. 追及时间 t2 = s2 / (v2 - v1)
5. 总耗时 T = t1 + t2
6. ∵ s2 = (p - s1 % p) < p ∴ s2 < p
7. ∵ s2 < p & t2 = s2 / (v2 - v1) ∴ t2 < p / (v2 - v1)
8. ∴ T = t1 + t2 < pos / v1 + p / (v2 - v1) 
9. 当v1 取极小值1，且v2也取极小值2时， 第8步不等式右边 **pos / v1 + p / (v2 - v1)** 可得到极大值 **S**
10. 所以T < S，即无论两人的速度差是多少，最多耗时都不会超过链表非循环部分的长度数量个单位时间

## 第三版，看了人家的题解后，发现可以优化一下第一版，利用Symbol类型值独一无二的特点，将hash替换成Symbol
> 88ms,36.7M。空间复杂度O(1)
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
var hasCycle = function(head) {
  const flag = Symbol();
  while(head) {
    if (head.val === flag) return true;
    head.val = flag;
    head = head.next;
  }
  return false;
};
```