### 解题思路
。。忘了字符串也有按位索引，然后用的数组

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    let nums = []
    nums = S.split("")
    for(let i = 0; i<nums.length;i++){
        let sum = 1
            for(let n = i+1; n<nums.length;n++){
            if(nums[i]==nums[n]){
                sum++
            }else if(nums[i]!=nums[n]){
                break
            }
    }
        nums.splice(i+1,sum-1)
        nums.splice(i,1,nums[i]+sum)  
    }
    if(S.length>nums.join("").length){
        return nums.join("")
    }else{
        return S
    }
};
```