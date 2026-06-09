### 解题思路
设一个i记录次数；
判断num是否为0；
执行While循环,对num和i进行处理，然后返回次数。
### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var numberOfSteps  = function(num) {
    let i=0;
    if (num===0) return i;
    while(num>0){
        num%2===0?(num/=2):(num--);
        i++
    }
    return i
};
```