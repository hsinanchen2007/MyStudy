```
var containsNearbyDuplicate = function (nums, k){
    if (k >= 10000 || k < 0) return false;
    return nums.some((item1,i) => nums.some((item2, j) => i !==j && item1 == item2 && Math.abs(i-j) <= k  ))
}
```
some() 方法测试数组中是不是至少有1个元素通过了被提供的函数测试。它返回的是一个Boolean类型的值。