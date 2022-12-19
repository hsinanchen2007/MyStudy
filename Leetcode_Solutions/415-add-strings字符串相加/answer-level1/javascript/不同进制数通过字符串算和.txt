```
// 题目；字符串模拟十进制相加
var num1 = "9333852702227987"
var num2 = "85731737104263"
// var num1 = "9133"
// var num2 = "0"
// 结果："9419584439332250"
var arrNum1 = num1.split('').reverse()
var arrNum2 = num2.split('').reverse()
console.log('arrNum1--',arrNum1)
console.log('arrNum2--',arrNum2)
// 补零
var l = arrNum1.length
var ls = arrNum2.length
if(arrNum2.length > arrNum1.length){
    l = arrNum2.length
    ls = arrNum1.length
}
console.log('l--',l)
function addZero (arr){
    if(arr.length<l){
        for(var i=0; i<l - ls; i++){
            arr.push('0')
        }        
    }
    return arr
}
var resultArr1 = addZero(arrNum1)
var resultArr2 = addZero(arrNum2)
console.log('补零数组--',resultArr1)
console.log('补零数组--',resultArr2)
var result = []
var count = 0
for(var i=0; i<l; i++){
    var add = (+resultArr1[i]) + (+resultArr2[i]) + count
    if(add<10){
        result[i] = add
        count = 0
        console.log('过程数组1--',i,result[i])
    }else{                   
        result[i] = add -10
        count = 1    
        console.log('过程数组2--',i,result[i])    
    }
}
// 最后高位
if(count == 1){
    result.push(1)
}
result = result.reverse().join('')
console.log('结果数组--',result)
```
总结这类题：（朴素解法）

- 相似问题：不同进制数通过字符串算和
- 相似解法：
    1. 字符串转数组
    2. 数组反转补零
    3. 数组进位求和
    4. 结果反转数组
         
         
         

