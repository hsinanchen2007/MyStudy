*法一：暴力挨个判断*

```js
/**
 * @param {number} left
 * @param {number} right
 * @return {number[]}
 */
var selfDividingNumbers = function(left, right) {
    // 判断是否是自除数
    let isSelfDividingNumber = function(num) {
        let arr = [];
        let num2 = num;
        if (num2 === 0) {
            return false
        }
        while(num > 0) {
            arr.unshift(num % 10);
            num = parseInt(num / 10)
        }
        for (let item of arr) {
            if (num2 % item !== 0) {
                return false
            }
        }
        return true
    }
    let res = []
    for (let i = left; i <= right; i++) {
        if (isSelfDividingNumber(i)) {
            res.push(i)
        }
    }
    return res;
};
var left = 1;
var right = 22;
console.log(selfDividingNumbers(left, right));
```

*法二：优化法一*

```js
var selfDividingNumbers = function (left, right) {
    let arr = [];
    for(let i = left; i <= right; i++) {
        if (i < 10) {
            arr.push(i);
        } else if (i > 10) {
            let n = i.toString();
            let flag = true;
            for (let j = 0; j < n.length; j++) {
                if (i % n[j] !== 0) {
                    flag = false
                }
            }
            if (flag) {
                arr.push(i)
            }
        }
    }
    return arr
};
```

