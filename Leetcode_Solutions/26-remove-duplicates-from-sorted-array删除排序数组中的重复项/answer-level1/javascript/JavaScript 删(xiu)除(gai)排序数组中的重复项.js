解一：
> 第一反应就是「删除」重复元素。这里循环需要注意，`nums.length`会随着`nums.splice`的执行而改变，所以在`for`循环中我们不是每次都需要`i++`。

```js
var removeDuplicates = function (nums) {
    var cur = nums[0];
    for (var i = 1; i < nums.length;) {
        if (nums[i] === cur)
            nums.splice(i, 1);
        else
            cur = nums[i++];
    }
    return nums.length
};
```

解二：
> 看了题解发现，实际上「修改」数组的前几位就够了。（这锅我不背，谁让大标题是“删除”呢）
> 由于不需要`splice()`，所以速度和内存占用都优化了不少。

```js
var removeDuplicates = function (nums) {
    var len = 1;
    for (var i = 1; i < nums.length; i++)
        if (nums[i] != nums[i-1]) nums[len++] = nums[i];
    return len
};
```
![](https://pic.leetcode-cn.com/58049329e4aab62dea795d2742d5f4289e14205b8eea5a7bc5b4ae7c1e1912cd-file_1565317825884)
