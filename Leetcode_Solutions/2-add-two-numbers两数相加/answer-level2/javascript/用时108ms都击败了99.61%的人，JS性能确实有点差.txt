### 解题思路
链表转数组 -> 数组转数字 -> 求和 -> 输出结果

### 代码

```javascript
var addTwoNumbers = function(l1, l2) {
    // 链表转数组
    const arr1 = [l1 && l1.val || 0]
    while(l1.next) {
        l1 = l1.next
        arr1.push(l1.val)
    }

    // 链表转数组
    const arr2 = [l2 && l2.val || 0]
    while(l2.next) {
        l2 = l2.next
        arr2.push(l2.val)
    }

    // 数组转数字并求和
    const num1 = BigInt(arr1.reverse().join(''))
    const num2 = BigInt(arr2.reverse().join(''))
    const sum = String((num1 + num2)).split('')

    // 输出结果
    let last = null
    for(let i = 0; i < sum.length; i++) {
        const current = new ListNode(sum[i])
        current.next = last
        last = current
    }
    return last
};
```