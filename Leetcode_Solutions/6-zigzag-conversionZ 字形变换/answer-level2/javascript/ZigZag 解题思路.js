### 解题思路
此处撰写解题思路
参考题解里大神思路，可以将该题看做是向长度为numRows大小的数组里添加元素，最后利用join()方法拼接为字符串
该题的重点是从小到大开始添加字符串，到数组最后一个元素时，添加顺序将反转，从大到小添加字符串，直至所有字符串被添加到数组中
### 代码

```javascript
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    let sA = s.split('')
    let i = 0, arr = [], flag = false
    if (numRows === 1) return s
    while(sA.length && i < numRows) {
        debugger
        arr[i]  = arr[i] ? arr[i] + (sA.shift()) : sA.shift()
        if (i === numRows - 1) {
            flag = true
        } else  if (i === 0){
           flag = false
        }
        if (flag === true) {
           i--
        } else {
           i++
        }
        
    }
    return arr.join('')
};
```