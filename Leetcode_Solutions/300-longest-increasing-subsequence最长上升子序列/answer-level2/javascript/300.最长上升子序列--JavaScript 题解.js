
- 维护一个降序数组 arr 和 最长序列个数 count
- 数组从右到左遍历
- 如果元素比arr[count]小，则直接插入 arr 中，count加一
- 否则找到 arr 中比它小的第一个数覆盖
- 最后返回 count

```
eg: 
[10，9，2，5，3，7，101，18]
count   arr
1       18
1       101
2       101,7
3       101,7,3
3       101,7,5
4       101,7,5,2
4       101,9,5,2
4       101,10,5,2
```
```
var lengthOfLIS = function(nums) {
    var len = nums.length;
    if(!len) return 0;
    var count = 1;
    var arr = [];
    arr[count] = nums[len-1];

    for(var i = len - 2;i >= 0;i--){
        if(nums[i] < arr[count]){
            arr[++count] = nums[i]
        }
        else{
            // 此处可以用二分进行优化
            for(var j = 1;j<=count;j++){
                if(arr[j]<=nums[i]) {
                    arr[j] = nums[i];
                    j = count + 1;
                }
            }
        }
    }
    return count;
};
```
