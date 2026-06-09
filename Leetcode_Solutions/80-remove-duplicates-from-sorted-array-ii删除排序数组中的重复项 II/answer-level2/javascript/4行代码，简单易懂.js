###解法一：

```js
var removeDuplicates = function(nums) {
    let i = 0;
    for(let n of nums) {
        if(i < 2 || n > nums[i - 2]) nums[i++] = n;
    }
    return i;
};
```

###解法二：

```js
var removeDuplicates = function(nums) {
    for(let i = 0; i < nums.length;){
        if(nums[i] === nums[i+1] && nums[i] === nums[i+2]) {
            nums.splice(i + 2, 1);
        }else {
            i++;
        }
    }
    return nums.length
};
```