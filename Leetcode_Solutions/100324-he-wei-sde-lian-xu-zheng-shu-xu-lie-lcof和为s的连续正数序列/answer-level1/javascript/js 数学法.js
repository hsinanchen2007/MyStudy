### 解题思路
第一次双百,萌新激动。
**数学法双百(56ms,34.1MB)**
首项a1,n项,差1,等差数列的和就是target,反过来求a1,判断是否为整数
**暴力法用时(256ms,36.8MB)**


### 代码

数学法
```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function (target) {
    let output = []
    for (n = 2; ; n++) {
        let a1 = (target -n*(n-1)/2)/n
        if (a1 < 1) break
        if (Number.isInteger(a1)) {
            let arr = []
            for (j = n; j > 0; j--) {
                arr.push(a1)
                a1++
            }
            output.unshift(arr)
        }
    }
    return output
};
```


暴力法
```js
    var findContinuousSequence = function (target) {
        let mid = Math.ceil(target / 2)
        let output = []
        for (i = mid; i > 1; i--) {
            let j = i
            let sum = i
            let arr = [i]
            while (sum < target && j > 0) {
                console.log('while');
                j--
                sum += j
                arr.push(j)
            }
            if (sum === target) {
                output.push(arr)
            }
        }
        return output
    }; 

```