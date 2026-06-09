### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * **解决：**
 * 一个从头遍历，一个从目标数字的开方往回遍历，如果目标数字大于实际数字，则i++;如果目标数字小于实际数字，
 * 则j–-;如果目标数字等于实际数字，则找到了;
 * 开方  Math.sqrt(c) 取整 parseInt()
 * @param {number} c
 * @return {boolean}
 */
var judgeSquareSum = function(c) {
    let i = 0, j= parseInt(Math.sqrt(c)); 
    while(i <= j){
        let sum = i*i + j*j
        if(sum == c){
            return true
        }else if(sum > c){
            j--
        }else if(sum <= c){
            i++
        }
    }
    return false
};
```