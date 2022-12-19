只需遍历一遍数组，时间复杂度O(N)。

```
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var checkPossibility = function(nums) {
    
    //不满足单调不减次数
    let count = 0;
    //不满足单调不减的位置
    let index = 0;
    
    //寻找不满足单调不减的位置；超过一个不满足单调不减的位置，返回false
    for(let i = 0; i <nums.length - 1; ++i){
        if(nums[i] > nums[i + 1]){
            index = i;
            ++count;
            if(count > 1) return false;
        } 
    }
    
    //端点情况：
    //如果index == 0，那么数列单调不减或修改第一个数后，可以单调不减
    //如果index == nums.length - 2 那么修改最后一个数后，可以单调不减
    if((index == 0) || (index == nums.length - 2)){
        return true;
    }
    //其余可以变成单调不减的情况：nums[index]大了或者nums[index+1]小了
    //修改nums[index]后，可以单调不减
    else if(nums[index-1] <= nums[index + 1]){
        return true;
    }
    //修改nums[index+1]后，可以单调不减
    else if(nums[index] <= nums[index + 2]){
        return true;
    }
    //其余情况不能通过修改至多一个数，使得数列单调不减
    else{
        return false;
    }
    
};
```
