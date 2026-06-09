### 解题思路
1. nodeList: {val: *, next: {}}
2. reverse()
3. arguments.callee()
4. BigInt("xxx")

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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let arr1 = [], arr2 = [];
    function getlistVal(list, arr){
        arr.push(list.val);
         if(list.next){
            arguments.callee(list.next, arr)
        }

    }
    getlistVal(l1, arr1);
    getlistVal(l2, arr2);
    
    let sum = BigInt(arr1.reverse().join('')) + BigInt(arr2.reverse().join(''));
    
    let res = (sum+'').split('').reverse();
    console.log("res:", res);

    function genNodeList(list){
        if(list.length == 0){
            return
        }
        return {
            val: list[0] * 1,
            next: genNodeList(list.slice(1))
        }
    }
    let nodeList = genNodeList(res)

    console.log("nodeList", nodeList);
    return nodeList
};
```