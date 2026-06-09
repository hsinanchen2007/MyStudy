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
 * @return {number}
 */
var getDecimalValue = function(head) {
    const bits = [];
    while(head){
        bits.unshift(head.val); //把每个位放进数组
        head = head.next;
    }

    let res = 0, bit = 0;
    for(let b of bits){
        if(b){
            res+=Math.pow(2, bit); //根据0或者1决定是否计算该位的对应的十进制数字，然后累加到结果
        }
        bit++;
    }
    return res;
};
```