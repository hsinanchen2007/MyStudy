```
var moveZeroes = function(nums) {
    let len = nums.length-1;
	for(let i =0;i<len;i++){
        if(nums[i]===0){
            nums.splice(i,1)
            nums.push(0)
			i--
            len--
        }
    }
    
};

```
咱也不知道对不对，咱也不敢问。。。我发现别的语言都是比较谁速度快内存少，咱们js就图个代码少