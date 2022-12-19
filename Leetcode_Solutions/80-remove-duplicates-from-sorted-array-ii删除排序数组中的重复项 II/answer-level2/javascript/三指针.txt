```js
var removeDuplicates = function(nums) {
    if(nums.length < 3) return nums.length;
    for(var i=0,j=1,k=2;i<j&&j<k&&k<nums.length;){
        if(nums[i] !== nums[j]){
            i++;
            j = i + 1;
            k = j + 1;
        }else{
            if(nums[j] === nums[k]){
                nums.splice(k, 1);
            }else{
                i = k;
                j = i + 1;
                k = j + 1;
            }
        }
    }
    return nums.length;
};
```