### 解题思路
1.判断是否是负数的情况
2.判断末尾是否为0的情况
3.利用字符串转数组进行反转
4.最后根据反转的结果，和规定的数值范围进行对比

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    if(!x) return x
    let arr = JSON.stringify(x).split('');
    if(arr[0] >=1){
        let val = arr.reverse().join('')
        if(val >= (Math.pow(2,31) -1) || val <= -Math.pow(2,31)) return 0
        return val
    }else{
        if(arr[0] === '-'){
            arr.shift()
            let val = '-' + arr.reverse().join('')
            if(val >= (Math.pow(2,31) -1) || val <= -Math.pow(2,31)) return 0
            return val
        }
        if(arr[arr.length-1] === 0){
            arr.pop()
            let val = arr.reverse().join('')
            if(val >= (Math.pow(2,31) -1) || val <= -Math.pow(2,31)) return 0
            return val
        }
    }
};
```