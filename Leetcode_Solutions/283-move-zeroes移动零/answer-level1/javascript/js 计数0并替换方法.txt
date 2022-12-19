统计零的个数，当零的个数大于0且遇上不等于0的将之向前替换；最后替换结束，数组中还缺少count0个0，逆序替换为0
```
var moveZeroes0 = function(nums) {
    let len = nums.length
    if(len <= 1) return nums
    let index0 = nums.indexOf(0)
    if(index0 === -1) return nums
    let count0 = 1
    for(let i = index0 + 1; i < len; i++){
        if(nums[i] !== 0 && count0 > 0){
            nums[index0] = nums[i]
            index0++
        }else{
            count0 += 1
        }
    }
    if(count0 > 0){
        for(let i = len-1; count0 > 0; i--,count0--){
            nums[i] = 0
        }
    }
};
```
