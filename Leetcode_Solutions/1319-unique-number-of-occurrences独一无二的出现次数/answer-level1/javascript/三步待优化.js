```
var arr = [-3,0,1,-3,1,1,1,-3,10,0]
var arr1 = [] // 非重复数组
var arr2 = [] // 存计数数组
var arr3 = [] // 结果转存数组
// 非重复数
for(var i=0; i<arr.length; i++){
    if(arr1.indexOf(arr[i]) === -1){
        arr1.push(arr[i])
    }
}
console.log('arr1', arr1)
// 计数
for(var i=0; i<arr1.length; i++){
    var count = 0
    arr.forEach(item => {
        if(arr1[i] === item){
            count++
        }
    })
    arr2.push(count)
}
console.log('arr2', arr2)
// 结果
for(var i=0; i<arr2.length; i++){
   if(arr3.indexOf(arr2[i]) === -1){
      arr3.push(arr2[i])
   }
}
if(arr3.length !== arr2.length){
    console.log(false)
}else{
    console.log(true)
}
```
执行用时 :80 ms, 在所有 javascript 提交中击败了13.93%的用户
内存消耗 :34.7 MB, 在所有 javascript 提交中击败了100.00%的用户