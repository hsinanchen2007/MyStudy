# 1.两数之和

https://leetcode-cn.com/problems/two-sum/

## 分析

- nums 中，任意 两个 不重复 的元素（整数），相加 = target
- 假设只存在一种情况

## 解

### 1.暴力

- 遍历，当前项，i，**_O(n)_**
  - 当前项下，遍历，后面的项，j，**_O(n)_**
  - i+j=target，返回 [i,j]
  - !=，j++
  - 遍历完 i 下面，所有的 j
  - 当前项结束，i++，重复以上

- T **_O(n²)_**
- S **_O(1)_**

```js
const twoSum = function (nums, target) {
  let len = nums.length
  let i = 0

  while (i < len - 1) {
    let j = i + 1

    while (j < len) {
      const sum = nums[i] + nums[j]
      if (sum === target) {
        return [i, j]
      }
      j++
    }
    i++
  }
}
```

### 2.map

- 用 map 保存每一项，key 为 []值（判断需要的数是否存在），val 为 []下标（返回下标）
- [3,5] => {3:0,5:1}
- 每次遍历的时候检查 map 中是否存在符合的 另一项，和当前项 相加 = target
- map 中检查，复杂度 **_O(1)_**，原来遍历的 j **_O(n)_**

- 遍历，当前项，i，**_O(n)_**
  - 当前项下，检查 map 中是否存在另一项，j，**_O(1)_**
  - i+j=target，返回 [i,j]
  - 当前项结束，i++，重复以上

- T **_O(n)_**
- S **_O(n)_**

```js
const twoSum = function (nums, target) {
  let len = nums.length
  let i = 0
  const obj = {}

  while (i < len) {
    const cur = nums[i]
    const rest = target - cur
    if (typeof obj[rest] !== 'undefined') return [i, obj[rest]]
    obj[cur] = i
    i++
  }
}
```
