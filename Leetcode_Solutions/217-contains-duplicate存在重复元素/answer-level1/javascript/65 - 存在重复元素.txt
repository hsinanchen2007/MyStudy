# 65 - 存在重复元素

## 题目

给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:

> 输入: [1,2,3,1]
> 输出: true

示例 2:

> 输入: [1,2,3,4]
> 输出: false

示例 3:

> 输入: [1,1,1,3,3,4,3,2,4,2]
> 输出: true

## 解答

只要有一样的元素，就输出true。那么可以用哈希表存一下已经有的内容，也可以用`indexof`来找相同的值，也可以排序后查一下后面有没有一样的值

这次题目很刺激，一下子想到了三种解法，还都写出来了，感觉自己很酷哈～😎😎

### indexof

从上一个题目解答获得的灵感，查一下后面有没有相同的数

```js
var containsDuplicate = function (nums) {
  for (let i = 0; i < nums.length - 1; i++) {
    if (nums.indexOf(nums[i], i + 1) !== -1) {
      return true;
    }
  }
  return false;
};
```

> Runtime: 1584 ms, faster than 9.87% of JavaScript online submissions for Contains Duplicate.
>
> Memory Usage: 37.2 MB, less than 94.12% of JavaScript online submissions for Contains Duplicate.

```go
func containsDuplicate(nums []int) bool {
	for i := 0; i < len(nums)-1; i++ {
		for j := i + 1; j < len(nums); j++ {
			if nums[i] == nums[j] {
				return true
			}
		}
	}
	return false
}
```

> Runtime: 784 ms, faster than 5.13% of Go online submissions forContains Duplicate.
>
> Memory Usage: 6.4 MB, less than 100.00% of Go online submissions for Contains Duplicate.

go没有现成的`indexOf`函数，只能手写一个。。

倒不如先排序一下。

### sort

```js
var containsDuplicate = function (nums) {
  nums.sort()
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] == nums[i + 1]) {
      return true
    }
  }
  return false
};
```

> Runtime: 96 ms, faster than 24.68% of JavaScript online submissions for Contains Duplicate.
>
> Memory Usage: 38.5 MB, less than 91.18% of JavaScript online submissions for Contains Duplicate.

```go
func containsDuplicate(nums []int) bool {
	sort.Ints(nums)
	for i := 0; i < len(nums)-1; i++ {
		if nums[i] == nums[i+1] {
			return true
		}
	}
	return false
}
```

> Runtime: 24 ms, faster than 49.49% of Go online submissions forContains Duplicate.
>
> Memory Usage: 6.4 MB, less than 100.00% of Go online submissions for Contains Duplicate.

go的做法要用到`sort`包，而且遍历的长度要`-1`，不然会导致panic，因为切片指向了一个不存在的地方。

但js里面不需要管那么多，因为即使指了数组之外，也是`undefined`，也是不想等的。

### map

```js
var containsDuplicate = function (nums) {
  let data = new Map()
  for (let i = 0; i < nums.length; i++) {
    if (data.has(nums[i])) {
      return true
    }
    data.set(nums[i], true)
  }
  return false
};
```

> Runtime: 60 ms, faster than 91.75% of JavaScript online submissions for Contains Duplicate.
>
> Memory Usage: 41.6 MB, less than 41.18% of JavaScript online submissions for Contains Duplicate.

这个方法速度贼快哈

```go
func containsDuplicate(nums []int) bool {
	data := make(map[int]bool)
	for i := 0; i < len(nums); i++ {
		if _, ok := data[nums[i]]; ok {
			return true
		}
		data[nums[i]] = true
	}
	return false
}
```

> Runtime: 20 ms, faster than 87.06% of Go online submissions forContains Duplicate.
>
> Memory Usage: 9.2 MB, less than 25.00% of Go online submissions forContains Duplicate.

### set

> 作者：pandawakaka
>
> 链接：https://leetcode-cn.com/problems/contains-duplicate/solution/cun-zai-zhong-fu-de-yuan-su-python3ji-he-fa-by-pan/

用set去重后，判断一下两者长度是否相同，很酷的解法哈。

```js
var containsDuplicate = function (nums) {
  data = new Set(nums)
  if (data.size === nums.length) {
    return false
  } else {
    return true
  }
};
```

> Runtime: 56 ms, faster than 97.51% of JavaScript online submissions for Contains Duplicate.
>
> Memory Usage: 40.9 MB, less than 61.76% of JavaScript online submissions for Contains Duplicate.

set的长度要用`size`来得到，和数组有些不同哈

go里面同样没有set，[实现的方法](https://studygolang.com/articles/11179)是用map，而这就和map的解法重复了，因此就不写了。


