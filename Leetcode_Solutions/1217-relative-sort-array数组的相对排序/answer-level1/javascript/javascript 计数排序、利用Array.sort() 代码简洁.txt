思路1：根据 Array.sort((a,b) => a - b) compareFunction 的规则，直接按题意进行排序
- 如果 compareFunction(a, b) < 0，则 a 会被排列到 b 之前；
- 如果 compareFunction(a, b) > 0，则 b 会被排列到 a 之前；
- 如果 compareFunction(a, b) == 0 ， a 和 b 的相对位置不变

思路2: 考虑到面试时，可能不让用sort API的情况，我们还可以用 计数排序
- 一个需要说明的点，因为范围只是0-1000，而索引肯定是升序的，可以利用数组的索引index来帮我们进行最后剩余整数的排序



```javascript
/**
 * 1122. Relative Sort Array
 * https://leetcode-cn.com/problems/relative-sort-array/
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number[]}
 */
// 解法一：Array.sort()
const relativeSortArray = (arr1, arr2) => {
  arr1.sort((a, b) => {
    let aIndex = arr2.indexOf(a), bIndex = arr2.indexOf(b)
    if (aIndex === -1 && bIndex === -1) return a - b
    if (aIndex === -1) return 1
    if (bIndex === -1) return -1
    return aIndex - bIndex
  })
  return arr1
}

// 解法二：计数排序
const relativeSortArray = (arr1, arr2) => {
  let result = [], countArray = new Array(1001)
  arr1.forEach(num => { countArray[num] = countArray[num] ? countArray[num] + 1 : 1 })
  arr2.forEach(num => {
    while(countArray[num]) {
      result.push(num)
      countArray[num]--
    }
  })
  for (let i = 0; i < countArray.length; ++i) {
    while (countArray[i] >= 1) { result.push(i); countArray[i]-- }
  }
  return result
}
```