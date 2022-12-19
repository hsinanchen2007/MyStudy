废话不多说，
直接上代码。

```
var findNumbers = function(nums) {
    let count = 0;
    for(let i = 0; i < nums.length; i++) {
        if(nums[i].toString().length % 2 === 0) count ++;
    }
    return count;
};
```
