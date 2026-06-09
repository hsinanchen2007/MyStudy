```
var s = '"aA"'
var arrS = s.split('')
var arrSA = []
var arrSI = []
console.log(arrS)
// 提炼
for(var i=0; i<arrS.length; i++){
    if(arrS[i] == 'a' || arrS[i] == 'e' || arrS[i] == 'i' || arrS[i] == 'o' || arrS[i] == 'u' || arrS[i] == 'A' || arrS[i] == 'E' || arrS[i] == 'I' || arrS[i] == 'O' || arrS[i] == 'U'){
        arrSA.push(arrS[i])
        arrSI.push(i)
        arrS.splice(i,1,0)
    }
}
arrSA = arrSA.reverse()
console.log('arrSA',arrSA)
console.log('arrSI',arrSI)
console.log('arrS',arrS)
// 倒叙后插入
for(var i=0; i<arrSI.length; i++){
    arrS[arrSI[i]] = arrSA[i] 
}
console.log('结果arrS--',arrS.join(''))
```
执行用时超过100%的用户，有点小兴奋虽然用了枚举，hihihi~
