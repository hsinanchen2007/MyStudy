### 解题思路
没有官方的那么优雅，看到题目的第一反应就是用`splice`。
使用一个临时数组，将数组中的每一个元素存入临时数组中，如果元素没有在临时数组中出现过，则将该元素加入数组，若是出现过，则就地删除这个元素

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    if (nums == []) return 0;
    var tmp = [];
    for(let i = 0; i < nums.length; i++){
        if(nums[i] == tmp[tmp.length - 1]){ // 该元素在数组中已存在，删除该元素
            nums.splice(i,1);
            i--; // 此时nums的长度会发生变化
        }else{
            tmp.push(nums[i])
        }
    }

    return nums.length;

};
```