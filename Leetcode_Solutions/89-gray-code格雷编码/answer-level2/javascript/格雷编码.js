### 解题思路
观察得出，格雷编码具有对称关系，获取上一个幂的值，然后从头和尾向中间加1，0，最后返回的数组每一项转成10进制

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var grayCode = function(n) {
   let make = (n)=>{
       if(n==0){
           return ['0']
       } else if(n==1){
           return ['0','1']
       } else {
           let prev = make(n-1)//获取上一个幂的数组值
           let max = Math.pow(2,n)-1
           let result = []
           for(let i=0;i<prev.length;i++){//利用对撞指针的方式添加到目标数组
               result[i] = `0${prev[i]}`
               result[max-i] = `1${prev[i]}`
           }
           return result
       }
   }
    return make(n).map(item=>{
               return parseInt(item,2)
           })
};
```