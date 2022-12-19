### 解题思路
1.外层从数组下标为0的元素开始遍历整个数组
2.内层则遍历外层从数组下标+1开始的下一个元素
3.在二者相等则找到目标值
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    let res;
    for(var x = 0 ; x < nums.length;x++){
        for(var y = x+1 ; y < nums.length;y++){
            if(nums[x] === nums[y] ){
                res =  nums[x]
            }
        }
    }
    return res;
}

```