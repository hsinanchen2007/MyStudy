思路：先把字符串分隔成多个数组，然后把数组反转。
```
var reverseWords = function(s) {
    let arr=s.split(' ')
    let result=arr.map(item=>{
        return item.split('').reverse().join('')
    })
    return result.join(' ')
}
```
为了让代码看起来更优雅：
```
var reverseWords = function(s) {
    return s.split(' ').map(item=>{
        return item.split('').reverse().join('')
    }).join(' ')
}
```
拓展1：还有没有其他的方法？
```
var reverseWords = function(s) {
    return s.split('/\s/g').map(item=>{
        return item.split('').reverse().join('')
    }).join(' ')
}
```
拓展2：不使用split()能实现吗？
```
var reverseWords = function(s) {
    return s.match(/[\w']+/g).map(item=>{
        return item.split('').reverse().join('')
    }).join(' ')
}
```

