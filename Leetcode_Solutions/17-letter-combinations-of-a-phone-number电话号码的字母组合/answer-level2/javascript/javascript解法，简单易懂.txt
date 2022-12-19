```
var letterCombinations = function(digits) {
    if (digits.length === 0) {
        return []
    }
    const map = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];
    if (digits.length === 1) {
        return map[digits].split("")
    }
    let arr = digits.split(""), result = map[arr[0]].split("");
    arr = arr.map(item => {
        return map[item];
    });
    arr.splice(0, 1);

    let count = (arr) => {
        let newArr = [...result];
        result.length = 0;
        for (let i = 0, len = newArr.length; i < len; i++) {
            for (let j = 0, len2 = arr[0].length; j < len2; j++) {
                result.push(`${newArr[i]}${arr[0][j]}`);
            }
        }
        arr.splice(0, 1);
        if (arr.length > 0) {
           return count(arr); 
        }
        return result;
    };
    return count(arr);
};
```

创建新数组保存前面计算的结果再将原数组置空。
