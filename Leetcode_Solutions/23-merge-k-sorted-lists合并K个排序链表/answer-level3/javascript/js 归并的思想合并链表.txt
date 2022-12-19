![image.png](https://pic.leetcode-cn.com/8863c0f7b6ccdd03c2eef9fb9e1e1ae2a4234a0384ad1f872fa9bd5a337e1802-image.png)

### 解题思路
```js
归并 + 分治
优化：跟下面方法唯一的区别是两个链表归并地来合并，而不是第一个合并第二个，
这个再合并第三个，这个再合并第四个
```

### 疑问？
为什么归并地合并就比相邻的链表依次去合并快这么多呢？哪位大佬能给我指点下？🙏

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
 * @param {ListNode[]} lists
 * @return {ListNode}
 */

var mergeKLists = function(lists) {
  let ans = new ListNode( -Infinity ), queue = [];
  
  queue = [...lists];
  while (queue.length > 1) {
    let first = queue.shift(),
        second = queue.shift();
    let c = merge(first, second);
    queue.push( c );
  }
  
  return queue.shift() || null;
};

function merge(l1, l2) {
  let newList = new ListNode( 0 ), p = newList;
  
  while (l1 && l2) {
    if (l1.val < l2.val) {
      p.next = l1;
      p = p.next;
      l1 = l1.next;
    } else {
      p.next = l2;
      p = p.next;
      l2 = l2.next;
    }
  }
  
  if (l1 !== null) p.next = l1;
  if (l2 !== null) p.next = l2;
  
  return newList.next;
}

/*
  260ms
  分治法：每次合并两个链表
*/
// var mergeKLists = function(lists) {
//   let ans = new ListNode( -Infinity );
  
//   for (let i = 0; i < lists.length; i++) {
//     if (lists[i] === null) continue;
//     ans = merge(ans, lists[i]);
//   }
  
//   return ans.next;
// };

// function merge(l1, l2) {
//   let newList = new ListNode( 0 ), p = newList;
  
//   while (l1 && l2) {
//     if (l1.val < l2.val) {
//       p.next = l1;
//       p = p.next;
//       l1 = l1.next;
//     } else {
//       p.next = l2;
//       p = p.next;
//       l2 = l2.next;
//     }
//   }
  
//   if (l1 !== null) p.next = l1;
//   if (l2 !== null) p.next = l2;
  
//   return newList.next;
// }



```