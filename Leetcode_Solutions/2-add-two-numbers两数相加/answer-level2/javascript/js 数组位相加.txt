```js
var addTwoNumbers = function(l1, l2) {
    let num1 = []
    let num2 = []
    let node1 = l1
    let node2 = l2
    while (node1) {
        num1.push(node1.val)
        node1 = node1.next
    }
    while (node2) {
        num2.push(node2.val)
        node2 = node2.next
    }
    let ret = resloveNumber(num1, num2)
    let node = {
        val: null,
        next: null
    }
    let head = node
    for (let i = 0; i < ret.length; i++) {
        node.next = {
            val: ret[i],
            next: null
        }
        node = node.next
    }
    return head.next
};
/**
 * 
 * @param {Array[]} arr1 
 * @param {Array[]} arr2 
 * @returns {Array[]}
 */
function resloveNumber (arr1, arr2) {
    let len = Math.max(arr1.length, arr2.length)
    for (let i = 0; i < len; i++) {
        if (arr1[i] == undefined) arr1[i] = 0
        if (arr2[i] == undefined) arr2[i] = 0
    }
    let temp = 0
    let ret = []
    for (let i = 0; i < len; i++) {
        ret[i] = arr1[i] + arr2[i] + temp
        if (ret[i] >= 10) {
            temp = 1
            ret[i] = ret[i] % 10
            if (i == len - 1) {
                ret[len] = 1
            }
        }
        else {
            temp = 0
        }
    }
    return ret
}
```