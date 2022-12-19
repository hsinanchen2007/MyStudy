设置两个下标i,j;
循环nums，
比较nums[i]和nums[i-1];如果发现不同，则将nums[j] 重置为nums[i];
```javascript []
var removeDuplicates = function(nums) {
    if(nums.length <=1){
        return nums;
    }
    let j=1;
    for(let i=1;i<nums.length; i++){
        if(nums[i]!=nums[i-1]){
            nums[j]=nums[i];
            j++;
        }
    }
    return j;
};
```
