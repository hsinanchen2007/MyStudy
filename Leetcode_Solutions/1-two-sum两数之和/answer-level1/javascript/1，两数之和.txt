方法一，暴力
```
var twoSum = function(nums, target) {
    for(let i = 0,len = nums.length;i<len;i++){
        for(let j = i+1;j<len;j++){
            if(nums[i]+nums[j] == target) return [i,j];
         }
    }
};
```
方法二，hash表
```
var twoSum = function(nums, target) {
    let map = {};
    for(let i = 0,len = nums.length;i<len;i++){
        if(map.hasOwnProperty(target - nums[i])){
            return [map[target - nums[i]],i];
           }
        map[nums[i]] = i;
    }
};
```
方法三，直接数组索引
```
var twoSum = function(nums, target) {
    for(let i = 0,len = nums.length;i<len;i++){
        let index = nums.indexOf(target - nums[i]);
        if(i!=index&&index != -1){
            return [i ,index];
        }
    }
};
```
以下这种方案适合返回数组中何为目标的值而不是索引，时间复杂度上是O(logn+n)
```
var twoSum = function(nums, target) {
    nums.sort((a,b)=>a-b);
    let left = 0,right = nums.length-1;
    while(left != right){
        let val = nums[left]+nums[right]-target;
        if(val > 0) right--;
        if(val < 0) left++;
        if(val == 0) return [nums[left],nums[right]];
    }
    return [];
};
```


