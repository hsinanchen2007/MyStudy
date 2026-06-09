```
// 非顺序查找指定字符串
// 返回num
var text = "nlaebolko"
var textArr = text.split('')
var str = "balon"
var strArr = str.split('')
var arrNum = []
var num1 = 0
var num2 = 0
textArr.forEach(item => {
    if('l' === item){
        num1++
    }else if('o' === item){
        num2++
    }
})
for(var i=0; i<strArr.length; i++){
    var count = 0
    textArr.forEach(item => {
        if(strArr[i] === item){
            count++
        }
    })
    if(count){
        arrNum.push(count)
    }
}
arrNum[2] = parseInt(arrNum[2]/2)
arrNum[3] = parseInt(arrNum[3]/2)
if(arrNum.length >= strArr.length && num1>=2 && num2>=2 ){
    var min = arrNum[0]
    arrNum.forEach(item => {
        if(item < min){
            min = item
        }
    })
    console.log('arrNum', arrNum)
    console.log('min', min)     
}else{
    console.log(0)
}

```

执行用时 :68 ms, 在所有 javascript 提交中击败了92.39%的用户
内存消耗 :35 MB, 在所有 javascript 提交中击败了100.00%的用户
