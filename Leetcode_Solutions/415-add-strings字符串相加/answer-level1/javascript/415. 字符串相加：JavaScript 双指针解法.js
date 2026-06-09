本题用双指针来解，注意判断进位就好。另外注意：如果最后一次循环后，`carry == 1`，因为没有再多一次的循环了，所以这个 `carry` 进位不会被加到 `res` 上。所以需要在 `return` 之前判断 `carry == 1`，为 `true` 则手动进位。

### 代码

```javascript
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function(num1, num2) {
    let i = num1.length - 1;
    let j = num2.length - 1;
    let carry = 0;
    let res = '';

    while (i >= 0 || j >= 0) {
        let n1 = i >= 0 ? num1[i] : 0;
        let n2 = j >= 0 ? num2[j] : 0;
        let tmp = Number(n1) + Number(n2) + carry;
        res = (tmp % 10) + res;
        carry = Math.floor(tmp / 10)
        i--;
        j--;
    }
    if(carry == 1) res = carry + res;
    return res;
};
```

**复杂度分析：**

- O(max(M,N))
- O(1)

---

**更多题解请关注**：[https://github.com/leviding/leetcode-js-leviding](https://github.com/leviding/leetcode-js-leviding)
