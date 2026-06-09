count变量记录当前位置前面有几个与val值相同的元素，代表着当前位置元素**需要向前移动多少位**。全部遍历完成后count代表数组存在多少与val相同的元素，所以返回总长度减去count即可
```javascript
var removeElement = function(nums, val) {
    let count = 0
    for(let i = 0; i < nums.length; i ++) {
        if (nums[i] === val) {
            count ++
        } else {
            nums[i - count] = nums[i]
        }
    }
    return nums.length - count
};
```
