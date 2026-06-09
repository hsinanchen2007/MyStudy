### 解题思路
优先考虑实现方法，没有考虑优化方式。主要是通过reduce来实现入栈方式，进行数值反转。

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    if(String(x==0||Math.abs(x)).length>32) return 0;
    if(Math.abs(x)<10) return x;
    let flag = x>0?1:0;
    let arr = String(Math.abs(x)).split('');
    let res = arr.reduce((pre,cur)=>{
        if(Array.isArray(pre)){
            pre.unshift(cur);
            return pre;
        }
        let newArr = [];
        newArr.push(cur,pre);
        return newArr;
    });
    let num = flag?Number(res.join('')):-Number(res.join(''));
    return Math.pow(-2,31)<=num && num<=Math.pow(2,31)-1?num:0;
};
```