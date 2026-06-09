转码
```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var grayCode = function(n) {
    let ans = [];
    let head = 1;
    ans.push(0);
    for(let i = 0; i < n;i ++) {
        let len = ans.length - 1;
        for(let j = len; j >=0; j--) {
            ans.push(head + ans[j])
        }
        // 位运算: b1等于b1乘以2的1次方
        head <<=1;
    }
    return ans;
};
```
时间复杂度: O(2^N)
空间复杂度: O(1)