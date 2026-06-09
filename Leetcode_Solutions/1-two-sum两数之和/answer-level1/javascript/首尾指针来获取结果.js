### 解题思路
通过首尾指针来获取结果

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const copy_nums = nums.concat()
    nums.sort((a,b)=>a-b) // 排序
    let front = 0  //首指针
    let behind = nums.length-1  //  尾指针
    while(front<behind){
        let res = nums[front]+nums[behind]
        if(res == target){
            front = copy_nums.indexOf(nums[front]) //原始数组中的位置
            behind = copy_nums.lastIndexOf(nums[behind]) // 原始数组中的位置
            return [front,behind]
        }else if(res>target)
        {
            behind = behind-1
        }else if(res<target)
        {
            front = front +1
        }
    }
    return [-1,-1]
};
```