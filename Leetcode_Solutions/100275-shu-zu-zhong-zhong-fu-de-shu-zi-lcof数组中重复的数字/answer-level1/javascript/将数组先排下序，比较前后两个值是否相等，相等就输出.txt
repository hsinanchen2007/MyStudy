### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    if(nums.length === 0){
        return false;
    }
    const numsSort = nums.sort((a,b)=>{
        return a - b;
    })
    for(let i = 1; i< numsSort.length; i++){
        if(numsSort[i] ===numsSort[i-1]){
            return numsSort[i]
        }
    }
};
```