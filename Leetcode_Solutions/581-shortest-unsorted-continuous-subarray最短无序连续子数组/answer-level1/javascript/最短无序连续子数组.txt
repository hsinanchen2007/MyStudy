排序后，双指针对比

```js
var findUnsortedSubarray = function(nums) {
    let nums2 = [...nums];
    nums.sort((a, b) => a - b);
    let i = 0;
    let j = nums.length-1;
    while(i < j) {
    	if (nums[i] === nums2[i]) {
    		i++;
    	} else if(nums[j] === nums2[j]) {
    		j--;
    	} else if (nums[i] !== nums2[i] && nums[j] !== nums2[j]) {
    		break;
    	}
    }
    if (i === j) {
    	return 0
    } else {
    	return j - i + 1
    }
};
```

