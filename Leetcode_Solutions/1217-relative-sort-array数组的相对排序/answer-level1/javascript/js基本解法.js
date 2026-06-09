```
var arr1 = [2,3,1,3,2,4,6,19,9,2,7]
var arr2 = [2,1,4,3,9,6]
var arr = []
var arrNew = []
// 该元素推进新数组
for(var i=0; i<arr2.length; i++){
    for(var j=0; j<arr1.length; j++){
        if(arr2[i] == arr1[j]){
            arr.push(arr1[j])
        }
    }
}
console.log('结果数组1--',arr)
// 多余元素推进另一新数组
for(var i=0; i<arr1.length; i++){
    if(arr.indexOf(arr1[i]) == -1){
        arrNew.push(arr1[i])
    }
}
// 另一新数组排序
arrNew.sort(function(a,b){return a - b})
console.log('结果数组2--',arrNew)
arr = arr.concat(arrNew)
console.log('结果数组3--',arr)
```
没有用到特殊的算法基本上就是按照题意来的。
1. 执行用时：80ms
2. 内存消耗：34.6MB