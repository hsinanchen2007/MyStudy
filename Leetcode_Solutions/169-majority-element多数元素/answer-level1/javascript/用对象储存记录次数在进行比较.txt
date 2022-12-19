### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    var ret = {};
    for(var i=0;i<nums.length;i++){
        if(ret[nums[i]]){
            ret[nums[i]]++;
        }else{
            ret[nums[i]]=1;
        }
    }
    let bi = Math.floor(nums.length/2);
    for(var x in ret){
        if(ret[x]>bi){
            return x;
        }
    }
};
```