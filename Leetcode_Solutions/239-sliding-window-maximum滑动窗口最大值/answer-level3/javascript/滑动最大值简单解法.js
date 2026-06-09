1、首先解决的问题是移动的截取数组
```
// 可以采用 数组的方法 slice
// 如何动态
//原数组：[1,3,-1,5,3,6,7]
[1,3,-1] slice(0,3)
[3,-1,5] slice(1,3)
[-1,5,3] slice(2,3)
[5,3,6]  slice(3,3)
[3,6,7]  slice(4,3)
// 第一个参数，动态 原数组.length-3+1 为最大移动距离
// 第二个参数 3 已经可以拿到

```
2、然后解决比较大小的问题
```
//可以使用Math.max的方法进行比较，但是数组没有这个方法
Math.max.apply(null,arr)
```
3、源码结果
```
var maxSlidingWindow = function(nums, k) {
    let numbers = nums.length-k+1
    let result = []
    if(nums.length!=0){
        for(var i=0;i<numbers;i++){
            result.push(Math.max.apply(null,nums.slice(i,i+k)) ) 
        }
    }
    return result
};
```


