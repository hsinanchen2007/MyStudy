### 解题思路
冒泡排序外层循环控制冒泡次数，题目中需要第k大的，每一次冒泡会比较出一个最大的，那k次比较就可以得到第k大的

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findKthLargest = function(nums, k) {
    //冒泡排序外层循环控制冒泡次数
    //题目中需要第k大的，每一次冒泡会比较出一个最大的，那k次比较就可以得到第k大的
    let tmp;
    let len=nums.length-1;
    for(let i=len;i>len-k;i--){
        for(let j=0;j<i;j++){
            if(nums[j]>nums[j+1]){
                let tmp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=tmp; 
            }
        }
    }
   console.log(nums);
    return nums[len-k+1];
};
```