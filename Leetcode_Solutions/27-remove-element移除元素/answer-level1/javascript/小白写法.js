用时：64ms，内存33.6MB
思路：遍历数组，查询数组中是否存在val项，如果存在就把该项移除，最后返回数组长度
```
    var removeElement = function(nums, val) {
      let len = nums.length;
      let index;
      for (let i = 0; i < len; i++) {
        index = nums.indexOf(val);
        if (index <= -1) break;
        nums.splice(index, 1);
      }
      return nums.length;
    };
```
