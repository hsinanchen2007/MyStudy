### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let i = 0;
    for (let j = 0; j < nums.length; j++) {
        if (nums[j] != nums[i]) 
            nums[++i] = nums[j];
    }
    return ++i;
};
```

### js最高赞解法

[链接在此](https://leetcode.com/problems/remove-duplicates-from-sorted-array/discuss/248020)

```javascript
var removeDuplicates = function(nums) {
	let i = 0;
	for (let j = 0; j < nums.length; j++) {
			if (nums[j] != nums[i]) 
					nums[++i] = nums[j];
	}
	return ++i;
};
```