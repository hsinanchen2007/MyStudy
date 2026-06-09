1. 新建一个map 遍历nums 如果map 中没有键为nums[i]的元素则向map中添加一个键为nums[i],值为1 的项,如果存在则键为nums[i]的值+1
2. 遍历这个map 如果值大于Math.floor(nums.length / 3)则向结果数组中加入这个键

```javascript
    var majorityElement = function(nums) {
    const map = new Map(),
      res = []
    let length = nums.length
    for (let i = 0; i < length; i++) {
      let value = nums[i]
      if (!map.has(value)) {
        map.set(value, 1)
      } else {
        map.set(value, map.get(value) + 1)
      }
    }

    for (const key of map) {
      if (key[1] > Math.floor(length / 3)) {
        res.push(key[0])
      }
    }

    return res
};
```
