
![zchanr.jpg](https://pic.leetcode-cn.com/ddbb0b39a56b7834f685fc9d9ac605d1faa7180c63ede0e6a7ef9d64c86334da-zchanr.jpg)

```
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    if(numRows===0)return ''
    if(numRows===1)return s
    var isDown = false
    var nowRow = 0
    var array = new Array(numRows).fill('')
    array.forEach.call(s,val=>{
        array[nowRow]+=val
        if(nowRow===numRows-1){
            isDown = false
        } else if(nowRow===0){
            isDown = true
        }
        nowRow+=isDown?1:-1
    })
    return array.join('')
};
```