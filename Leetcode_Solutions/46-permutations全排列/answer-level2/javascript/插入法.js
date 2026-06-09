```
/**
     * @param {number[]} nums
     * @return {number[][]}
     * 插入法全匹配
     */
    const permute = (nums) => {
      let result = [
          [nums[0]]
        ],
        j = undefined,
        arr = []
      for (let i = 1; i < nums.length; i++) { // 不断插入新的排列数
        arr = [] // 将临时变量置空
        result.forEach((value) => {
          value.push(nums[i]) // 对上一次的全排列都插入新的排列数
          // arr.push(JSON.parse(JSON.stringify(value)))
          arr.push([...value])
          j = value.length - 1
          while (j > 0) { // 将新排列数插入到不同位置
            [value[j - 1], value[j]] = [value[j], value[j - 1]]
            // arr.push(JSON.parse(JSON.stringify(value)))
            arr.push([...value])
            j--
          }
        })
        result = arr
      }
      return result
    }
```