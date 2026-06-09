### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    let temp = s,
        reg = new RegExp(/(\((1*)\))/ig);

    while(reg.test(temp)){
        temp = temp.replace(reg,1+'$2');
    }
    let arr = temp.split(/[\(\)]/ig);
    return arr.reduce((total,item,index)=>{
        let len = item.length*2;
        total = total > len ? total : len;
        return total;
    },0)
     
};
```