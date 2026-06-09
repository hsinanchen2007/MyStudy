```
var arr = [3,8,-10,23,19,-4,-14,27]
var arr1 = arr.sort(function(a,b){return a-b})
var arr2 = [] // 存差值
var arr3 = [] // 存单项
var arr4 = [] // 存结果数组
console.log('arr1',arr1)
// 差数组
for(var i=0; i<arr.length; i++){
    if(arr[i+1] - arr[i]){
        arr2.push(Math.abs(arr[i+1] - arr[i]))
    }
}
console.log('arr2',arr2)
// 最小差
var min = arr2[0]
for(var i=0; i<arr2.length; i++){
    if(arr2[i]<min){
        min = arr2[i]
    }
}
console.log('min', min)
// 结果双重数组
for(var i=0; i<arr.length; i++){
    if(Math.abs(arr[i+1] - arr[i]) === min){
        arr3.push(arr[i],arr[i+1])
    }
    if(arr3.length){
        arr4.push(arr3)
    }
    arr3 = []
}
console.log(arr4)
```

执行用时 :200 ms, 在所有 javascript 提交中击败了83.33%的用户
内存消耗 :50.8 MB, 在所有 javascript 提交中击败了100.00%的用户