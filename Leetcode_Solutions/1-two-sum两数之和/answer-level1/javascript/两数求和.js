### 解题思路
通过双for循环这种暴力解法,事件复杂度为O(N^2)过高。
设置两个数一个为num另外一个为target-num可以减少依次遍历。利用Object存储已经遍历的数据项可以方便查找。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
   let len=nums.length-1,obj={};
    for(let i=0;i<=len;i++){
      if(obj.hasOwnProperty(target-nums[i])){
          return [i,obj[target-nums[i]]]
      }else{
          obj[nums[i]]=i;
      }
    }  
};
```