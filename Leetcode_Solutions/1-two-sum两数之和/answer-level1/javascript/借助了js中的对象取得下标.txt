### 解题思路
借助了js中的对象取得下标

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const obj = nums.reduce((pre,cur,i)=>{ pre[cur]=i;return pre },{})
    
    for(var i =0 ; i< nums.length; i++){
         const index = obj[target-nums[i]]
         if(index!==undefined && index!==i ) return [i,index]
    }
};
```