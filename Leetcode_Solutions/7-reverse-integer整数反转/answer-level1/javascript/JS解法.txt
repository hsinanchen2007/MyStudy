### 解题思路
先判断保存x的正负情况，转换为字符串进行循环，向前添加，最后进行判断正负和溢出情况，返回结果。

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let flag=x>0?true:false
    let a=x.toString(),num='';
    for(let i=0;i<a.length;i++){
        num=a[i].toString()+num
    }
    if(flag){
        return parseInt(num)>2**31-1?0:parseInt(num)
    }else{
        return -parseInt(num)<(-2)**31?0:-parseInt(num)
    }
};
```