### 解题思路
此处撰写解题思路
一个略微改版的二分查找。
定义一个result 作为返回结果，初始化为 [-1, -1]
当找到mid 下标的值为目标值时，首先判断result[0]里是否已经存了，
  如果不存在，说明我们还没找到最左值，于是记录当前的end(待会我们要回来找最右值，所以要记录)，因为怕end被覆盖，所以加个判断
   如果左边已经和目标值不相等，或者已经是最左了，那么就记录当前的值为最左值，同时，回到刚才我们记录的end那里，开始搜索最右值
  如果存在了，那么说明我们现在是往右搜索，我们一直记录当前值，使用覆盖的方法找到最右值
其他情况和正常二分查找一样。
### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    let result = [-1, -1]
    let start = 0, end = nums.length - 1, first = -1
    do {
        mid = start + Math.floor((end - start) / 2)
        if( nums[mid] === target) {
            if(result[0] === -1) {
                first = first === -1 ? end : first;
                if(mid === 0 || nums[mid - 1] !== target) {
                    result[0] = mid;
                    result[1] = mid;
                    start = mid+1;
                    end = first;
                } else {
                    end -- ;
                    continue;
                }
            } else {
                result[1] = mid;
                start = mid + 1;
            }
        } else if(nums[mid] < target){
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }while(start<=end)
    return result
};
```