### 解题思路
两种解答：1.遍历时删除所有0再在末尾拼接；2.双指针思想

### 代码

**1.删除0再末尾拼接**
```javascript
//去除数组中所有的0，遍历结束后再把0拼接到数组上
var moveZeroes = function(nums) {
    let len = nums.length;
    let n=0;
    for(let i=0;i<len;i++){
        if(nums[i]===0){
            nums.splice(i,1);
            i--;
            n++;
        }
    }
    for(let j=0;j<n;j++){nums.push(0);}
    return nums;
};
```

**2.双指针思想**
```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let len = nums.length;
    let i,j=0;
    //j为慢指针，i为常规遍历的指针
    //当j值不为0时：i和j同时往前走；
    //当j值为0时：如i值非零则j值和i值交换后i和j同时往前走；如i值为零则i继续往前走j不动。
    for(i=1;i<len;i++){
        if(nums[j]!==0){
            j++;          
        }
        else if(nums[i]!==0){
            nums[j] = nums[i];
            nums[i] = 0;
            j++;
        }        
    }
    return nums;
};
```