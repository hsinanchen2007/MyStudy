### 解题思路
新建一个数组，遍历去要重的数组，当值不在新数组的时候（indexOf为-1）就加入该新数组中
新旧数组比较长度

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    var hash=[];
    for (var i = 0; i < nums.length; i++) {
     if(hash.indexOf(nums[i])==-1){
      hash.push(nums[i]);
     }
  }
    if (hash.length == nums.length){
        return false
    } else{
        return true
    }
};
```