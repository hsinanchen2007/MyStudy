### 解题思路
此处撰写解题思路

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
var middleNode = function(head) {
    let listLength = 0;
    for(let next = head; next !== null; next = next.next){
        listLength += 1;
    }
    let ans = null;
    if(listLength % 2 === 0){
        let tmp = listLength / 2 + 1;
        ans = head;
        for(let i = 1; i < tmp; i++){
            ans = ans.next;
        }
        return ans;
    }else{
        let tmp = listLength / 2;
        ans = head;
        for(let i = 1; i < tmp; i++){
            ans = ans.next;
        }
        return ans;
    }
};
```