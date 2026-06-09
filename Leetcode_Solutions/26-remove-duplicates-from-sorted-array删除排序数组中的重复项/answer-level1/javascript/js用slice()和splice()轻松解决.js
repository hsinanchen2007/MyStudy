![...de026删除排序数组中的重复项.mp4](c0004e2a-5af0-40ef-9ed4-82a975b16183)
```
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let len=nums.length;

    for(let i=1;i<len;){ 
        //slice(i,j) 截取下标i开始，下标j（不包括）结束的子数组
        if(nums.slice(0,i).indexOf(nums[i])!==-1){// 重复项
            nums.splice(i,1);//删除下标从i开始的，长度为1的子数组
            len--;
        }
        else i++;

    }
    return len;
};
```
