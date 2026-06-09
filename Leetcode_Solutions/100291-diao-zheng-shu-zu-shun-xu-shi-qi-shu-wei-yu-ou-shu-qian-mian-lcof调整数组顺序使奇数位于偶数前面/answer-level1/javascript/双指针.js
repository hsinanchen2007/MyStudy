### 解题思路
1. 定义头指针 left ，尾指针 right .
2. left 一直往右移，直到它指向的值为偶数
3. right 一直往左移， 直到它指向的值为奇数
4. 交换 nums[left]nums[left] 和 nums[right]nums[right] .
重复上述操作，直到 left == rightleft==right .



### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var exchange = function(nums) {
    let l = 0;
    let r = nums.length-1;
    while(l<r){
        //奇数
        if((nums[l] & 1)){
            l++;
            continue
        }
        //偶数
        else if(!(nums[r] & 1)){
            r--;
            continue
        }

        [nums[l],nums[r]] = [nums[r],nums[l]]
    }

    return nums
};
```