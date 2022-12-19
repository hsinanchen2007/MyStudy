### 解题思路
一次遍历，比较tempmax和resmax，，很巧妙。

### 代码

```javascript
/**
 * 遍历，比较tempmax和resmax，，很巧妙。
 */
var maxSubArray = function(nums) {
    if(nums==null) return 0
    var tempMax = nums[0]
    var resMax = nums[0]
    for(var i=1;i<nums.length;i++){
        if(tempMax > 0){
            tempMax += nums[i]
        }else{
            tempMax =nums[i]
        }
        resMax = Math.max(tempMax,resMax)
    }
    return resMax;
};













```