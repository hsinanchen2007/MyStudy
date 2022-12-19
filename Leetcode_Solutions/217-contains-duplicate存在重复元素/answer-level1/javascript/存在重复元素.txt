*法一：判断indexOf与lastIndexOf是否相等*

缺点：极慢，不推荐

```js
var containsDuplicate = function(nums) {
    let len = nums.length;
    for (let i = 0; i < len; i++) {
        if (nums.indexOf(nums[i]) !== nums.lastIndexOf(nums[i])) {
            return true
        }
    }
    return false
};
```

*法二：借用对象*

速度提升了不少，但消耗内存

```js
var containsDuplicate2 = function(nums) {
    let len = nums.length;
    let obj = {};
    for (let i = 0; i < len; i++) {
        if (!obj[nums[i]]) {
            obj[nums[i]] = true
        } else {
            return true
        }
    }
    return false
};
```

*法三：new Set(arr)*

- ES6中set的元素的唯一的,如果重复只取其一

优点：执行用时少，占用内存小，推荐

```js
var containsDuplicate3 = function(nums) {
    return !(new Set(nums).size === nums.length)
};
```

*法四：数组排序后比较相邻两项是否相等*

内存占用明显减少，但执行时间中等

```js
var containsDuplicate4 = function(nums) {
    nums.sort();
    let len = nums.length;
    for (let i = 0; i < len; i++) {
        if (nums[i] == nums[i+1]) {
            return true
        }
    }
    return false
};
```

