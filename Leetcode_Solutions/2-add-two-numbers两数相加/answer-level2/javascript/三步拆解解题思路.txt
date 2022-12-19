### 解题思路

第一步要将 链表 => 数组

第二步要 补全数组长度，将相同位置的数字相加，得到一个最终的数组

    例子：
    1000000000000000000000000000001
    +
    5640000000000000000000000000000
    ----------------------------------------
    6640000000000000000000000000001

第三步要将 数组 => 链表

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
    // 本题的难度并不复杂，只是阶梯的过程比较长
    // 第一步要将 链表 => 数组
    // 第二步要 补全数组长度，将相同位置的数字相加，得到一个最终的数组
    // 第三步要将 数组 => 链表

    return arrayToLink(sumArray(linkedToArray(l1), linkedToArray(l2)))
};

// 将 链表 转换成 数组
var linkedToArray = function(linked){
    let l = linked
    const array = []

    // 将 linked 转成 array
    do {
        array.push(l.val)
        l = l.next
    } while (!!l)

    return array
}

// 数组求和
var sumArray = function(arr1, arr2){
    const result = []
    // 区别数组长度
    let maxLen, minLen
    if (arr1.length >= arr2.length) {
        maxLen = arr1
        minLen = arr2
    } else {
        maxLen = arr2
        minLen = arr1
    }

    const arr = new Array(maxLen.length - minLen.length)
    for (let i=0; i<arr.length; i++) {
        arr[i] = 0
    }
    // 将两个数组的长度成一样的，使得计算方便
    minLen = minLen.concat(arr)

    let moreTen = 0
    for (let i=0; i<maxLen.length; i++) {
        let sum = maxLen[i] + minLen[i] + moreTen
        if (sum > 9) {
            result.push(sum % 10)
            moreTen = Math.floor(sum/10)
            if (i == maxLen.length-1) { // 最后一位时，需要将超过两位的拆开
                result.push(moreTen)
                break;
            }
        } else {
            result.push(sum)
            moreTen = 0
        }
    }

    return result
}

// 将数组 转成 链表
var arrayToLink = function(array){
    let linked = null
    for (let i=array.length-1; i>=0; i--) {
        const link = new ListNode(array[i])
        link.next = linked
        linked = link
    }

    return linked
}
```