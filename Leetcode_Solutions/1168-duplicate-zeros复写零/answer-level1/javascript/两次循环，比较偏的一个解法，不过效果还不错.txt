
执行用时 :96 ms, 在所有 JavaScript 提交中击败了91.67%的用户

内存消耗 :36 MB, 在所有 JavaScript 提交中击败了100.00%的用户

1. 找到0的位置，存数组、`let len=arr.length `
2. 循环位置数组，splice 
3. `arr.length == len;` 数组长度变回来
```
    /**
    * @param {number[]} arr
    * @return {void} Do not return anything, modify arr in-place instead.
    */
    var duplicateZeros = function(arr) {
        let len = arr.length;
        let r = [];
        for(let i = 0; i < len; i++) {
            if(arr[i] === 0) {
                r.push(i);
            }
        }
        for(let i = 0; i < r.length; i++) {
            arr.splice(r[i] + i, 0, 0);
        }
        arr.length = len;
    };
```
