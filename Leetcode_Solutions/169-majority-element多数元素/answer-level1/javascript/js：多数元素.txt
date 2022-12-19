### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let arr_len = nums.length;
    let MEN = arr_len / 2;
    let ME = null;
    let MEN_obj = {};
    for(let i = 0; i < arr_len; i++){
        if(MEN_obj[nums[i]] == undefined){
            MEN_obj[nums[i]] = 1;
        }else{
            MEN_obj[nums[i]] += 1;
        }
        if(MEN_obj[nums[i]] > MEN){
            ME = nums[i];
            break;
        }
    }
    return ME;
};
```