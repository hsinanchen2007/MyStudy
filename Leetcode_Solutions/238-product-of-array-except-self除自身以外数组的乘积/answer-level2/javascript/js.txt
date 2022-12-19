### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    let leftArr = []
    let rightArr = []
    for (let i = 0; i < nums.length; i++) {
        if (i === 0) {
            leftArr[0] = nums[0]
            rightArr[nums.length - 1] = nums[nums.length - 1]
        } else {
            leftArr[i] = nums[i] * leftArr[i - 1]
            rightArr[nums.length - i - 1] = nums[nums.length - i - 1] * rightArr[nums.length - i]
        }
    }
    let res = new Array(nums.length).fill('')
    res = res.map((ele, i) => {
        if(i === 0) {
            return rightArr[1]
        }
        if(i === nums.length - 1){
            return leftArr[nums.length - 2]
        }
        return rightArr[i + 1] * leftArr[i - 1]
    })
    return res
};
```