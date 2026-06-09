### 解题思路
通过二重循环将重复元素修改为字符'a', 在进行一次循环将'a'删除

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    for(let i=0; i<nums.length-1; i++){
        for(let j=i+1; j<nums.length; j++){
            if(nums[i]==nums[j]){
                nums[j] = 'a';
            }
        }
    }
    for(let i=nums.length; i>0; i--){
        if(nums[i]=='a'){
            for(let j=i; j<nums.length-1; j++){
                nums[j] = nums[j+1];
            }
            nums.length--;
        }
    }
    return nums.length;
};
```