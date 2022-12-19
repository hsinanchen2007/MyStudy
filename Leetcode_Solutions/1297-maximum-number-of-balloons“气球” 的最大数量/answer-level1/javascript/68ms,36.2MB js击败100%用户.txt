**思路：字符串中找特定字符，不用关注顺序**
***注意点：js中没有min方法，sort排序默认是按照字母升序的，直接排序数字需要传入函数作为参数***

```
/**
 * @param {string} text
 * @return {number}
 */
var maxNumberOfBalloons = function(text) {
    let targetArr = 'balloon'.split('')
    let resArr = text.split('')
    resArr = resArr.filter(item=>targetArr.includes(item))
    let B = resArr.filter(item=>item==='b') && resArr.filter(item=>item==='b').length
    let A = resArr.filter(item=>item==='a') && resArr.filter(item=>item==='a').length
    let L = resArr.filter(item=>item==='l') && resArr.filter(item=>item==='l').length/2
    let O = resArr.filter(item=>item==='o') && resArr.filter(item=>item==='o').length/2
    let N = resArr.filter(item=>item==='n') && resArr.filter(item=>item==='n').length
    return Math.floor([B,A,L,O,N].sort((a,b)=>a-b)[0])
};
```

