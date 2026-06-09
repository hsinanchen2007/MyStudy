### 读题阶段

**问题点**

从一个数组nums里找到两个元素，使得两元素之和等于目标值target，按顺序以数组形式返回两个元素的下标

**输入**

1. 数组nums
2. 目标值target

**输出**

以数组形式存储两个元素的下标

**注意点**

1. 输出数组的下标顺序
2. nums里的数字均为整数
3. 用例满足情况的答案只有唯一一种
4. 不能重复利用相同元素

### 思考阶段

**顺势思维**

> 顾名思义顺着题目的意思走

以 [2,7,11,19] 为例，所有组合情况：

2与7，11，19
7与11，19
11与19

那么数组大小为n的数组，可能的次数就是 (n - 1) + (n - 2) + .... + 1
最终可以得到：(n^2 - n)/2

`复杂度分析`

时间复杂度：O(n^2)
空间复杂度：——

`空间换时间`

O(n^2) ——> O(n)：能否只遍历一边？

**逆向思维**

> 从目标反推出条件，原因

假定找到数组的两个元素x、y，有 x + y = taregt 为唯一解

那么我们可以通过 target - x 来推得 y，即 y = target - x

以 [2,7,11,19] 为例，x = 2 时，y 便是 7

现在的问题是：若是以2，向右查找7，其实和顺势思维的方式就没有区别了

既然向右不行，那么我们需要向左查找，而左边是我们已经遍历过的，可以处理成哈希表：key为元素值，value为对应的下标

就得到了如下的算法：

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const map = new Map()
    for (let i in nums) {
        const key = nums[i]
        const anotheri = target - key
        if (map.has(anotheri)) {
            return [map.get(anotheri), i]
        } else {
            map.set(key, i)
        }
    }
};
```

`复杂度分析`

时间复杂度：O(n)
空间复杂度：O(n)

### 探究阶段

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
  const map = {}
  for (let i in nums) {
    const key = nums[i]
    const anotheri = map[target - key]
    if (anotheri >= 0) {
      return [anotheri, i]
    } else {
      map[key] = i
    }
  }
};
```

回收机制对于Map类型的支持更加优化，但是从执行时间上看用对象做哈希更高效。






