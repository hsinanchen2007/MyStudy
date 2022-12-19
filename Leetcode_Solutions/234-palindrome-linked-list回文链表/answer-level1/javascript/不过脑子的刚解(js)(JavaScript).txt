思路特别直接，循环读数然后头尾对比。
肯定连快都算不上，不过是个解法罢了。
具体优化怎么做请参照其他语言，js本来就快不了（我觉得）；

```
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
  let nums = [];
  while (head){
    nums.push(head.val);
    head = head.next;
  }
  
  while(nums.length > 1){
    if(nums.pop() != nums.shift()) return false;
  }
  return true;
};
```
