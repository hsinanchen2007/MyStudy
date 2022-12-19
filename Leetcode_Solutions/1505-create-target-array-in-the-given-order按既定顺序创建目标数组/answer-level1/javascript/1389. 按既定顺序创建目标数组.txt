### 解题思路
居然莫名其妙跑了双100

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number[]} index
 * @return {number[]}
 */
var createTargetArray = function(nums, index) {
    let result = new Array(index.length).fill(null)
    for(let i = 0; i < index.length; i++){
        let _index = index[i]
        result.splice(_index, 0, nums[i])
    }
    return result.filter(v => { return v !== null })
};
```