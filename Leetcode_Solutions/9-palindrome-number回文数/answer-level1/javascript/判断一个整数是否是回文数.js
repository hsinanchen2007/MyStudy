### 解题思路
负数肯定不是回文数，将整数变成数组，首尾进行比较

### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(x < 0) return false;
    let nums = String(x).split('');
    for(let i =0,j=nums.length -1;i<=j;i++){
        if(nums[i] !== nums[j]){
            return false;
        }
        j--;
    }
    return true;
};
```