执行用时 :68 ms, 在所有 JavaScript 提交中击败了97.66%的用户

内存消耗 :33.5 MB, 在所有 JavaScript 提交中击败了79.44%的用户
```
/**
* @param {number[]} digits
* @return {number[]}
*/
var plusOne = function(digits) {
    let f = true;
    for(let i = digits.length - 1; i > -1; i--) {
        if (f) {
            let t = digits[i] + 1;
            if(t < 10) {
                f = false;
            }
            digits[i] = t % 10;
            if(i === 0 && f) { // 最后一个都还是true
                digits.unshift(1);
            }
        } else {
            return digits;
        }
    }
    return digits;
};
```
