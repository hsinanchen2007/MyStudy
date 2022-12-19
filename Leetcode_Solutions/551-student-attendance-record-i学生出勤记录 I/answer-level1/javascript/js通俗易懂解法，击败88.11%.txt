```
/**
 * @param {string} s
 * @return {boolean}
 */
var checkRecord = function(s) {
    let i = 0;
    let countA = 0;
    while (i < s.length) {
        let curr = s.charAt(i);
        if (curr === "A") {
            countA++;
            if (countA > 1) {
                return false;
            }
        } else if (curr === "L") {
            if (s.charAt(i + 1) === "L" && s.charAt(i + 2) === "L") {
                return false;
            }
        }
        i++;
    }
    return true;
};
```
优化后的解法，代码更简洁，但是执行时间并没有提高多少，和前面一种差不多
```
/**
 * @param {string} s
 * @return {boolean}
 */
var checkRecord = function(s) {
     let i = 0;
    let countA = 0;
    while (i < s.length) {
        let curr = s.charAt(i);
        if (curr === "A") {
            countA++;
            if (countA > 1) {
                return false;
            }
        }
        i++;
    }
    return s.indexOf("LLL") < 0;
};
```
