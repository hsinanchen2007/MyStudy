```
var S = '(()())(())(()(()))'
// 从 0 开始计数，遇 a 则 +1 遇 b 则 -1 
// 当 a=1 且 b=0 就为最外层括号，记下序号
var arr = S.split('')
var indexArrB = []
var count = 0
console.log('arr--',arr)
for (var i=0; i<arr.length; i++) {
    if (arr[i] == '(') {
       count++ 
    } else {
       count--  
    }
    if(count==0){
        indexArrB.push(i)
    }
}
// console.log('序号数组其一--',indexArrB)
// 需要删除的元素序号
var indexArrA = []
for(var i=0; i<indexArrB.length-1; i++) {
    indexArrA.push(indexArrB[i]+1)
}
indexArrA.unshift(0)
// console.log('有序数组其二',indexArrA)
var index = indexArrA.concat(indexArrB)
console.log('index--',index)

var indexArr = []
for(var i=0; i<arr.length; i++){
    if(index.indexOf(i) == -1) {
        indexArr.push(arr[i])
    }
}
console.log('arr--',arr)
console.log('aaa--',indexArr)
console.log('合成--',indexArr.join(''))
```
大众思路：设基础值为0为别记录两种符号计算基础值，然后利用序号删掉相应符号。
此代码费时费力，但是......
