### 解题思路
见代码

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var decompressRLElist = function(nums) {
    // 计算数组长度
    let len = 0;
    for(let i=0;i<nums.length;i++) {
			len+=nums[i];
			i++;
	}
    // 填充
    let result = Array(len)
    let count = 0;
    for(let i=0;i<nums.length;i++) {
        for(let j=0;j<nums[i];j++) {
            result[count++] = nums[i+1];
        }
        i++;
    }
		
	return result;
};
```