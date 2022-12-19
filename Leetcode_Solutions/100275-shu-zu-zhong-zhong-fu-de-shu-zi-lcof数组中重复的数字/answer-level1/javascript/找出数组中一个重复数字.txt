### 解题思路
题目是找出其中一个重复的数字即可。先排序让数字重复的相邻，再遍历一下数组，判断数组里面当前数字与下一个数字是否相等即可。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    var _arr = nums.sort();
    for(let i=0;i<_arr.length-1;i++){
        if(_arr[i] == _arr[i+1]){
            return _arr[i]
        }
    }
};
```