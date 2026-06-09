
```javascript
/**
 * @param {number} n
 * @return {number}
 */
var sumNums = function(n) {

    //1.逻辑与运算符短路解法
    //return n + (n && sumNums(n-1))

    //2.映射-归约解法
    
        return [...new Array(n).keys()]
            .map( v => {
                return v + 1
            })
            .reduce( (pre,cur)=>{
                return pre + cur
            })
    
    
};
```