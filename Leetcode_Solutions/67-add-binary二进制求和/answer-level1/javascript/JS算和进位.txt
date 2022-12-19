```
// 模拟二进制计算
var a = '1'
var b = '111'
// 将两个字符串保持长度一致
var maxL = a.length > b.length ? a.length : b.length
var arrA1 = a.split('')
var arrB1 = b.split('')
var ca = maxL-arrA1.length
var cb = maxL-arrB1.length
if(maxL-arrA1.length > 0){
    for(var i=0; i<ca; i++){
        arrA1.unshift('0')
    }
}
if(maxL-arrB1.length > 0){
    for(var i=0; i<cb; i++){
        arrB1.unshift('0')
    }
}
var arrA = arrA1.reverse()
var arrB = arrB1.reverse()
console.log(arrA)
console.log(arrB)
// 通过求和决定需不需要进位，并且可以把上次进位清零
var arr = []
var count = 0
for(var i=0; i<arrA.length; i++){
    console.log('arrA[i]--',arrA[i])
    console.log('arrB[i]--',arrB[i])
    var sum = +(arrA[i]) + +(arrB[i]) + count
    console.log('sum--',sum)
    if(sum == 0){
        arr[i] = 0
        count = 0
    }else if(sum == 1){
        arr[i] = 1
        count = 0
    }else if(sum == 2){
        arr[i] = 0
        count = 1
    }else{
        arr[i] = 1
        count = 1
    }
}
// 最后一位进位
if(count == 1){
    arr.push(1)
}
console.log('结果--',arr.reverse().join(''))
```
不完全是自己写的，进位思路借用了一些和的思路，一开始自己直接用字符串与进位标志一起算导致没有办法清零，算和可以为进位符及时清零。
