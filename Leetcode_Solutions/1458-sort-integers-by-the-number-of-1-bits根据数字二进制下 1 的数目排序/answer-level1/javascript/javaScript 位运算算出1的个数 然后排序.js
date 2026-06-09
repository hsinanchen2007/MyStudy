### 解题思路
1. 用 num&1 判断二进制数末尾是否未 1
2. num右移一位 如此循环 直至 num 为 0，循环结束
3. 如此 就能得到每一个数的1个数
4. 再使用数组内置的 sort 对数组进行排序
### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {number[]}
 */
var sortByBits = function(arr) {
    let countBit = (num) => {
        let res = 0
        let s = num
        while(num) {
            // console.log(s, num , num & 1)
            if(num & 1) {
                res++
            }
            num>>=1
        }
        // console.log(s, res)
        return res
    }
    arr.sort((a, b) => {
        let res = countBit(a) - countBit(b)
        if (res === 0) return a - b
        return res
    })
    return arr
};
```