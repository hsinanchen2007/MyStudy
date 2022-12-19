![image.png](https://pic.leetcode-cn.com/0d3965ce3a33c77dcff5b7a0f5d4b7f4531979cb4442967b568fe4731889bfaa-image.png)

思路：两数相加都是从末位开始，对应位数改变且产生进位。两个二进制数字相加，从它们的末位开始遍历，若对应位数都是0，则依然是0，进位为0；若一个是0，一个是1，则变成1，进位为0；若两个都是1，则变为0，进位为1；若两个都是1，且进位为1，则变为0，进位为1；

因为二进制只有0，1，根据以上规律，容易联想到异或运算，即两数相同异或为0，0与任意数字异或为数字本身；所以相加的位数为 a[i] ^ b[j] ^ add；初始化进位add = 0，若 a[i] b[i] add 中有两个及两个以上数字为1，则add为1

遍历数组后，已更改全部位数，若此时进位为1，则需在首部添加1

```
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    let add = 0
    let sum = []
    for(let i = a.length -1, j = b.length -1; i >= 0 || j >= 0; i--, j--) {
        let num1 = +a[i] || 0
        let num2 = +b[j] || 0
        sum.unshift(num1 ^ num2 ^ add)
        add = num1 + num2 + add > 1 ? 1 : 0
        
    }
    if (add === 1) sum.unshift(1)
    return sum.join('')
};
```
