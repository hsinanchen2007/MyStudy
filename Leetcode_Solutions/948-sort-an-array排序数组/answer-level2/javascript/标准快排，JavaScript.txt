### 解题思路

![image.png](https://pic.leetcode-cn.com/ea6246828badb3359d414c49eeb53594b6972f589dfea7dd797f2cf6505b71d0-image.png)


### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(nums, low = 0, hight = nums.length - 1) {
    // return nums.sort((a,b) => a - b);
    //快排
    if(!nums.length) return;

    if(low < hight) {
        let index = getIndex(nums, low, hight);

        sortArray(nums, low, index - 1);
        sortArray(nums, index + 1, hight);
    }

    return nums;
};

function getIndex(nums, low, hight) {
   	let temp = nums[low];

    while(low < hight) {
        while(low < hight && nums[hight] >= temp) {
        	hight --;
        }
        nums[low] = nums[hight];

        while(low < hight && nums[low] <= temp) {
            low ++;
        }
        nums[hight] = nums[low]; 
    }
    nums[low] = temp;
    return low;
}
```