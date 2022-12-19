### 解题思路
- 头尾指针分别表示0的右边界和2的左边界
- 如果当前元素等于0，和头指针元素互换
- 等于2，和尾指针元素互换

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    let len = nums.length, cur = 0, p0 = 0, p1 = len -1
    while(cur <= p1){
        function swap(a,b){
            let temp = nums[a]
            nums[a] = nums[b]
            nums[b] = temp
        }
        if(nums[cur] === 0){
            swap(cur, p0)
            cur ++
            p0 ++
        }else if(nums[cur] === 2){
            swap(cur, p1)
            p1 --
        }else{
            cur ++
        }
    }
};
```