```
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
 var sortColors = function(nums) {
    let temp = new Array(3).fill(0);
    
    for(let i=0;i<nums.length;i++){
        temp[nums[i]] ++;
    }
    let k =0;

    for(let i=0;i<temp.length;i++){
        let length = temp[i];
        while(length>0){
            nums[k++] = i;
            length --;
        }
    }
    return nums;
};
```
