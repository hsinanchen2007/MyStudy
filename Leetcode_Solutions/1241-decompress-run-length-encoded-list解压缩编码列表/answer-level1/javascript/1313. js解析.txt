### 解题思路
数组的访问
列表的添加
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var decompressRLElist = function(nums) {
    list = []
    for(var i=0;i<nums.length;i+=2){
        for(var j=0;j<nums[i];j++){
            list.push(nums[i+1]);
        }
    }
    return list;
};
```