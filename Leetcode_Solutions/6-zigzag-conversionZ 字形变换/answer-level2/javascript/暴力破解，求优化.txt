### 解题思路
先用二维数组，用矩阵的方式存进去，然后再遍历取出。暴力破解
### 代码

```javascript
/**
 * @param {string} s
  * @param {number} numRows
   * @return {string}
    */
    
### 代码

```javascript
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    if(numRows === 1){
        return s
    }
    let res = []
    let len = 0
    let data = ''
    
    while(len<s.length){
        const tr = res.length
        let arr = new Array(numRows)
        if(tr%(numRows-1)===0){
            for(let i = 0;i<arr.length;i++){
               arr[i] = s[len]
               len++
            }
        }else{
            arr[(numRows-1)-tr%(numRows-1)] = s[len]
            len++
        }
        res.push(arr)
    }
    console.log(res)
    for(let j =0;j<numRows;j++){
        res.forEach(item=>{
            if(item[j]) data+=item[j]
        })
    }
    return data
};
```