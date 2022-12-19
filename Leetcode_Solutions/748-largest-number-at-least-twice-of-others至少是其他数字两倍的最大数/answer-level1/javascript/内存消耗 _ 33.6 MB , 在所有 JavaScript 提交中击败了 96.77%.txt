### 解题思路
执行用时 :
72 ms
, 在所有 JavaScript 提交中击败了
50.75%
的用户
内存消耗 :
33.6 MB
, 在所有 JavaScript 提交中击败了
96.77%
的用户
炫耀一下:

很惊讶会内存消耗在其他中会这么小，就分享一下写法吧，萌新不会算法。就会for循环。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var dominantIndex = function(nums) {
  
    var secs = 0;
    var max = 0;
    var kindex =0;
    for (var i=0;i<nums.length;i++) {
        if (nums[i]) {
             if(nums[i]>max) {
                secs = max;
                max = nums[i];
                kindex = i;
           } else {
               if(nums[i]>secs) {
                     secs = nums[i]
                  }
              
           }
        }
       
    }
    if (max/secs >=2) {
        return kindex;
    }else {
        return -1;
    }
};
```