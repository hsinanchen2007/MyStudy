### 解题思路
此处撰写解题思路

### 代码

```javascript
var letterCombinations = function (digits) {
    const Num2Char = [
        [],
        [],
        ["a", "b", "c"],
        ["d", "e", "f"],
        ["g", "h", "i"],
        ["j", "k", "l"],
        ["m", "n", "o"],
        ["p", "q", "r", "s"],
        ["t", "u", "v"],
        ["w", "x", "y", "z"]
    ]
    let res = []

    function dfs(str, index, item) {
        if (str.length == 0) {
            res = [];
            return
        }
        if (index == str.length) {
            res.push(item)
            return
        }
        let firstChar = str.substr(index, 1)
        let firstNum = parseInt(firstChar);
        // console.log(firstNum)
        for (let i = 0; i < Num2Char[firstNum].length; i++) {
            item = item + Num2Char[firstNum][i]
            dfs(str, index + 1, item);
            item = item.substr(0, item.length - 1)
        }
    }
    dfs(digits, 0, "")
    
   return res;
};
```