### 解题思路
找下一个排列得过程就是，从最后一项往前找，找第一个出现的 nums[i-1] < nums[i],
因为如果 后面得子数组 只要是降序，就一定不会有更大得子数组
找到i-1之后，让 i-1 与 后面出现得大于nums[i-1] 得所有项中最小得那个项交换，然后再对 i ~ length-1进行排序
得到得nums 就是要求得结果。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
/**
 1.找下一个排列得过程就是，从最后一项往前找，找第一个出现的 nums[i-1] < nums[i],
    因为如果 后面得子数组 只要是降序，就一定不会有更大得子数组
    找到i-1之后，让 i-1 与 后面出现得大于nums[i-1] 得所有项中最小得那个项交换，然后再对 i ~ length-1进行排序
    得到得nums 就是要求得结果。
 */
var nextPermutation = function(nums) {
   for(let i = nums.length-1; i>=0; i--){
       if(nums[i-1] < nums[i]){
           let min = nums[i];
           let k = i;
           for(j = i; j < nums.length; j++){
               if(nums[j] < min && nums[j] > nums[i-1]){
                   min = nums[j];
                   k = j;
                }
            }
            let t = nums[i-1];
            nums[i-1] = nums[k];
            nums[k] = t;
            let arr = nums.splice(i);
            arr.sort((a,b) => a-b);
            arr.forEach(item =>{
                nums.push(item);
            })
            return;
       }
   }
   nums.sort((a,b) => a-b) 
};
```