### 解题思路
arr长度 <= 3, 取第一位。长度 > 3， arr[i]===arr[i+1], num1加一， arr[i]!==arr[i+1],num1为0

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {number}
 */
var findSpecialInteger = function(arr) {
    if(arr.length <=3) return arr[0]
    let num = Math.ceil(arr.length * 0.25);
    let num1 = 0
    for(let i = 0; i < arr.length - 1; i++) {
        arr[i] === arr[i+1] ? num1 ++ : num1 = 0
        if (num === num1) {
            return arr[i]
        }
    }
};
```