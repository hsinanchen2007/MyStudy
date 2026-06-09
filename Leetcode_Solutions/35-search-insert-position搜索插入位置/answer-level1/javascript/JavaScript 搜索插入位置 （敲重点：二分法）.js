解一：
> 还是`indexOf`开头，如果存在返回索引值，否则就`push`一下给它生米煮成熟饭，再排序，重新返回索引值。

```js
var searchInsert = function (nums, target) {
    var index = nums.indexOf(target)
    if ( index != -1) return index
    nums.push(target);
    nums.sort(function (a, b) {
        return a - b
    })
    return nums.indexOf(target)
};
```

解二：
> 老实方法用`for`遍历，存在（`=`）和不存在（`>`）两种情况可以一起处理。

```js
var searchInsert = function (nums, target) {
    if (target<nums[0]) return 0
    for (var i = 0; i<nums.length;i++){
        if (nums[i]>=target) return i;
    }
    return i
};
```

解三：
> 使用二分法，也是这道题真正想考察的方法。
> 
> 二分法理解起来很简单，小学就学过。但是实际编码时，边界防范、左右中位数的取舍、`while`中的条件以及是否`+1`何处`+1`可以说是要处处设防。

```js
var searchInsert = function (nums, target) {
    var left = 0;
    var right = nums.length - 1;
    if (target > nums[right]) return right + 1;
    while (left < right) {
        var index = parseInt((left + right) >>> 1);//取左中位数
        if (nums[index] < target) left = index + 1; //中位数小于目标值，削去区间左侧
        else right = index; //中位数大于等于目标值，削去区间右侧
    }
    return left;
};
```
![](https://pic.leetcode-cn.com/647033c81d0b21e96eb086dc4a7c080dfeaf5224a2701f3cb0199d30322e78a5-file_1565334735141)

对需要注意的地方按顺序解释一下：
1. 初始区间的设置 `left = 0` `right = nums.length-1`。
2. 当`target`大于`nums`中最大的元素时，返回的索引值在区间外，为`nums.length`，因此提前进行判断。
3. `while`循环的条件为`left < right`，当`left = right`时跳出循环。
4. 中位数选取左中位数使用无符号右移`left + right >>> 1`防止溢出 （也可选取右中位数，但`if-else`也需要同时修改）
5. 在选取了左中位数的基础上，`if-else`需要保证左边界收缩，因此先写`left = index+1`，再根据`+1`填写`if`括号中的条件为`nums[index]<target`，再补全`else`即可。
    ![](https://pic.leetcode-cn.com/bb7951489673d5a4f2b9eb3b13ddac88ced38ffe6646163f511be6ec67c5f40b-file_1565334735398)
6. 由于只有在`left = right`时才能跳出循环，所以返回`left``right`均可。

参考资料：[【特别推荐】十分好用的二分查找法模板（Python 代码、Java 代码）](https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/)