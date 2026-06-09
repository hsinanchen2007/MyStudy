# 前端与算法 leetcode 27.移除元素
---
# 题目描述
[27.移除元素](https://leetcode-cn.com/problems/remove-element/)
# 概要
题目本身其实挺简单的,官方解答也说道了`人们可能会对"就地"一次感到困惑`,并认为在不复制数组的情况下从数组中删除元素是不可能的
# 提示
双指针,仅返回长度,元素顺序可以更改,元素很少时
# 解析
把题中的就地删除理解为覆盖,也就是说,只要我们找到一个和val一样的值,我们就把他覆盖掉,所以我们需要两个指针,一个快指针用来寻找和比较元素,一个慢指针用来覆盖元素,同时可以利用js的`length`的特性,在返回长度之前将数组的长度直接设置为我们计算的长度,这样的好处是我们可以直观的看到数组的结果,同时实现了真正意义上的修改原数组

### 算法
在这里考虑元素很少的情况,当`nums[j]`与给定的值不等时覆盖,相等时`length--`同时跳过该元素,也就是说最好的情况下,数组内所有元素都与参数相等,那么length自减到0同时直接返回0,最坏的情况下所有元素都不等,全部覆盖的同时返回length的,正常情况只要`nums[j]!==val`,我们就把他覆用j指向的数值覆盖掉,并递增i,重复这个过程一直到j到达数组的末尾,数组的新长度为`length`
```js
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
const removeElement = (nums, val) => {
  if (nums.length === 0) return 0
  let { length } = nums
  let [i, j] = [0, 0]
  while (j < nums.length) {
    if (nums[j] !== val) {
      nums[i] = nums[j]
      i++
    } else {
      length--
    }
    j++
  }
  nums.length = length
  return length
}
```
传入`[1, 3, 9, 6]`和3的运行结果
```sh
3
[ 1, 9, 6 ]
```
执行结果
```sh
执行用时 :64 ms, 在所有 javascript 提交中击败了91.87% 的用户
内存消耗 :33.7 MB, 在所有 javascript 提交中击败了33.58%的用户
```

## GitHub仓库

[1. 两数之和](https://github.com/moshuying/leetcode-cn/)