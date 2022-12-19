### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    const maps = {
        2: "abc",
        3: "def",
        4: "ghi",
        5: "jkl",
        6: "mno",
        7: "pqrs",
        8: "tuv",
        9: "wxyz"
    }
    let res = [];
    for (let num of digits) {
        let w = maps[num];
        if (res.length > 0) {
            let tmp = [];
            for (let i = 0; i < res.length; i++) {
                for (let j = 0; j < w.length; j++) {
                    tmp.push(res[i] + w[j])
                }
            }
            res = tmp;
        } else {
            res = [...w];
        }
    }
    return res;

};

```