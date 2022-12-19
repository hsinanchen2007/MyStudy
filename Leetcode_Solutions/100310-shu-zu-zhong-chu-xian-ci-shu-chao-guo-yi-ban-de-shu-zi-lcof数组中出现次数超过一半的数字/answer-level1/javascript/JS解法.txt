
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let n = nums.length;
    let obj = {};
    for(let i=0; i<n; i++){
        if(!obj[nums[i]]){
            obj[nums[i]] = 1;
        }else{
            obj[nums[i]]++;
        }
    }
    for(let key in obj){
        if(obj[key] > n/2){
            return key
        }
    }
};
```