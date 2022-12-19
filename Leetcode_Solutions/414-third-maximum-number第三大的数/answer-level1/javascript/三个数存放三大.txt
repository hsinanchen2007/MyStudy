### 解题思路
方法一、set

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var thirdMax = function(nums) {
    var set = new Set(nums)
    var arr = [...set];
    arr.sort((a,b)=>b-a);
    if(arr.length<3){
        return arr[0]
    }
    return arr[2];
};
```
方法二、三个数分别存放第一大、第二大、第三大
```
var thirdMax = function(nums) {
    var one = nums[0];
    var two = -Infinity;
    var three = -Infinity;
    for(var i=0;i<nums.length;i++){
        if(nums[i]==one || nums[i]==two || nums[i]==three) continue;
        if(nums[i]>one){
            three=two;
            two=one;
            one=nums[i];
        }else if(nums[i]>two){
            three=two;
            two=nums[i];
        }else if(nums[i]>three){
            three=nums[i];
        }
    }
    return nums.length >= 3 && three != -Infinity ? three : one
};
```

