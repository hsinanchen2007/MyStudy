1. 找出第k个排列
n 个元素有 n! 种排列方式，可转化为 n 个元素每个有 (n-1)! 种排列方式，取 k/(n-1)! 的商向上取整再减一为 idx，表示第k个排列是在数组的第 idx 个元素的排列方式里产生的；去掉数组的第 idx 元素避免重复选择，若 k 除以 (n-1)! 的余数为 0，表示取第 idx 元素下的第 (n-1)! 个排列；若不为0，表示取第 idx 元素第第xx余数个排列，n减1，进入递归循环；
当 n=1 时，数组内所有元素已取完，结束循环

```
/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getPermutation = function(n, k) {
    let str = ''
    let originlist = Object.keys(Array(n + 1).fill(0))
    originlist.shift()
    
    const factorial = (n) => {
        if (n < 1) return 1
        let result = 1
        while(n > 1) {
            result = result * n
            n--
        }
        return result
    }
    
    const sequenceFn = (list, n, k) => {
        const factorialResult = factorial(n - 1)
        const idx = Math.ceil(k/factorialResult) - 1
        str += list[idx]
        let newKey = k%factorialResult === 0 ? factorialResult : k%factorialResult
        let offset = k%(n-1) === 0 ? 0 : k%(n-1)
        if (n <= 1) {
            return
        }
        return sequenceFn([...list.slice(0, idx), ...list.slice(idx+1)], --n, newKey)
    }
    sequenceFn(originlist, n, k)
    return str
};
```

2. 依次找出前k个排列，然后结束循环，方法比较笨，需要在找到第k个时结束循环，否则可能会超出时间限制

```
/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getPermutation = function(n, k) {
    let list = Object.keys(Array(n+1).fill(0))
    list.shift()
    let len = list.length
    let arr = []
    let count = 0
    let target = []
    let getPermutation = (leftArr, rightArr) => {
        if (count === k) return
        if (leftArr.length === len) {
            target = leftArr.slice()
            count++
            return
        }
        for(let i = 0; i < rightArr.length; i++) {
            let ele = rightArr[i]
            leftArr.push(ele)
            getPermutation(leftArr, [...rightArr.slice(0, i), ...rightArr.slice(i+1)])
            leftArr.pop()
        }
    }
    getPermutation([], list)
    return target.join('')
};
```
