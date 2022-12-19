# Two Sum IV - Input is a BST

## 题目

给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

> 案例 1:
>
> 输入: 
>  5
> / \
> 3   6
> / \   \
> 2   4   7
>
> Target = 9

输出: True

> 案例 2:
>
> 输入: 
> 5
> / \
> 3   6
> / \   \
> 2   4   7
>
> Target = 28

输出: False

## 解答

### 第一种思路：整理成数组，回到two sum 2

把二叉树变成原来的升序数组，然后再用two sum 2的解法来做

#### 二分法

```js
var findTarget = function (root, target) {
  if (!root) {			// 基础判断
    return false;
  }
  
  let nums = []
  function inOrder(root) {
    if (!root) {
      return;
    }
    inOrder(root.left);
    nums.push(root.val);
    inOrder(root.right);
  }
  inOrder(root);

  // 以下是二分法的代码
  for (let index = 0; index < nums.length; index++) {
    const aim = target - nums[index];
    let start = index + 1;
        end = nums.length - 1;
    while (start <= end) {
      let mid = Math.round((start + end) / 2)
      if (nums[mid] === aim) {
        return true
      } else if (nums[mid] < aim) {
        start = mid + 1
      } else {
        end = mid - 1
      }
    }
  }
  return false
};
```

> Runtime: 88 ms, faster than 81.75% of JavaScript online submissions for Two Sum IV - Input is a BST.
>
> Memory Usage: 41.5 MB, less than 78.42% of JavaScript online submissions forTwo Sum IV - Input is a BST.

### 双指针

```js
var findTarget = function (root, target) {
...
  let low = 0;
  high = nums.length - 1;

  while (low < high) {
    let sum = nums[low] + nums[high];
    if (sum < target) {
      low++
    } else if (sum > target) {
      high--
    } else {
      return true
    }
  }
  return false
};
```

> Runtime: 88 ms, faster than 81.75% of JavaScript online submissions for Two Sum IV - Input is a BST.
>
> Memory Usage: 42.1 MB, less than 39.72% of JavaScript online submissions for Two Sum IV - Input is a BST.

好像表现也差不多

#### 一遍哈希表

```js
var findTarget = function (root, target) {
...
  const arrMap = new Map()
  for (let i = 0; i < nums.length; i++) {
    const result = target - nums[i];
    if (arrMap.has(result)) {
      return true
    }
    arrMap.set(nums[i], i)
  }
  return false
};
```

> Runtime: 76 ms, faster than 97.74% of JavaScript online submissions for Two Sum IV - Input is a BST.
>
> Memory Usage: 41.7 MB, less than 66.44% of JavaScript online submissions forTwo Sum IV - Input is a BST.

### 用对象呢？

```js
var findTarget = function (root, target) {
...
  const map = {}
  for (let i = 0; i < nums.length; i++) {
    const result = target - nums[i];
    if (map.hasOwnProperty(result)) {
      return true
    }
    map[nums[i]] = i;
  }
  return false
};
```

> Runtime: 104 ms, faster than 32.73% of JavaScript online submissions for Two Sum IV - Input is a BST.
>
> Memory Usage: 42.9 MB, less than 13.01% of JavaScript online submissions for Two Sum IV - Input is a BST.

总是要比map差一点，也不知道为什么

### 哈希表+两分法

和two sum 2的方法不同，需要多做一步判断，不然会出现多次用同一个数的情况。例子是[2,3]，target=6，显然是应该返回false。然而不加判断会返回true。

- 第一遍找不到4，于是把访问过的3加入哈希表{3 => 1}
- 第二遍开始查哈希表，要找3，正好有3，就返回了true。然而这两个3都是nums的第二位，用了同一个数字了。

在two sum2中可以实现，因为给的target总是对的，因此就不会出现这种的情况，也就不需要多加一步判断了。

```js
var findTarget = function (root, target) {
...
	const arrMap = new Map()
  for (let i = 0; i < nums.length; i++) {
    const aim = target - nums[i];
    if (arrMap.has(aim) && arrMap.get(aim) !== i) {  // 这里需要多做一步判断
      return true
    }

    let start = i + 1;
    end = nums.length - 1;
    while (start <= end) {
      let mid = Math.round((start + end) / 2)
      if (nums[mid] === aim) {
        return true
      } else if (nums[mid] < aim) {
        start = mid + 1
      } else {
        end = mid - 1
      }
      arrMap.set(nums[mid], mid)
    }
  }
  return false
};
```

> Runtime: 120 ms, faster than 13.88% of JavaScript online submissions for Two Sum IV - Input is a BST.
>
> Memory Usage: 41.7 MB, less than 67.50% of JavaScript online submissions for Two Sum IV - Input is a BST.



### 第二种思路：用二叉树的特性

跳过理顺为数组的环节，直接一个个拿出来比对

#### 深度优先搜索

```js
var findTarget = function (root, k) {
  let stack = [root] // 数组初始化，存入root
  let map = []

  while (stack.length > 0) {
    let cur = stack.pop()		// 每次把数组顶端的node拿出来

    if (map.includes(k - cur.val)) { // 在map数组内查询是否有
      return true
    }
    map.push(cur.val) // 没有就推入map数组

    if (cur.left) {
      stack.push(cur.left)
    }
    if (cur.right) {
      stack.push(cur.right)
    }
  }
  return false
};
```

因为右边是最后推入stack的，因此是从右往左的深度优先的查询。

> Runtime: 152 ms, faster than 5.88% of JavaScript online submissions for Two Sum IV - Input is a BST.
>
> Memory Usage: 42 MB, less than 45.20% of JavaScript online submissions forTwo Sum IV - Input is a BST.

不过感觉非常耗时……也许是因为map是数组的原因？`.includes()`查询比较耗时？

##### 换成obj呢？

```js
var findTarget = function (root, k) {
...
  let map = {}
...
    if (map.hasOwnProperty(k - cur.val)) {
      return true
    }
    map[cur.val] = true
...
};
```

> Runtime: 108 ms, faster than 27.23% of JavaScript online submissions for Two Sum IV - Input is a BST.
>
> Memory Usage: 42.9 MB, less than 13.93% of JavaScript online submissions for Two Sum IV - Input is a BST.

耗时降低了，但占用的内存增加了。这是在用空间换时间。

##### 换成map呢？

```js
var findTarget = function (root, k) {
...
  let map = new Map()
...
    if (map.has(k - cur.val)) { 
      return true
    }
    map.set(cur.val, true)
...
};
```

> Runtime: 104 ms, faster than 32.53% of JavaScript online submissions for Two Sum IV - Input is a BST.
>
> Memory Usage: 41.5 MB, less than 82.14% of JavaScript online submissions for Two Sum IV - Input is a BST.

似乎总是map最快

#### 既然知道了要找的内容，可以直接用二叉树找啊

思路分为两套循环，外循环是深度优先的遍历，内循环是根据当前节点`val`的二叉树的搜索。
曾经搜索过的，就放在`map`当中，启动内循环之前先看`map`当中有没有。

难点在于怎么判断在二叉树上的不同节点。换言之，在`map`中找到的值不是他自己。【哈希表+两分法中遇到的问题】
也就是二叉树的定位问题。。

感觉可以多保存一下位置信息，但即使能做到也把问题变得更加复杂了。。

## 二叉树参考

[JS 实现 二叉树](https://segmentfault.com/a/1190000011947724)

