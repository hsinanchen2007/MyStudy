![image.png](https://pic.leetcode-cn.com/94a7f4133524eba37566cf4b730b799b23d7be68032a0ecb19bb7f6a7e997897-image.png)
1. 思路分析 
    - 问题的重点 找到 **最靠近** 位于当前区间`current`**右侧的区间**     
    - 即找到当前的右界限`current[1]`小于等于 目标目标区间的左界限`target[0] `
    - 变成一个遍历一个数组 找数组的每一项比另一个数组中其中一项小的问题 
        - 存在 则记录下下标 
        - 否则 记录`-1`
    - 首先要该方法要查找 而且目标数组（可排序） 首先选择二分法
    - 但是找到之我们需要获得真实的下标 可以直接采用map的形式存储每个区间的坐标
2. 解题步骤
    - 每个区间的第一个元素不重复 则以第一个元素为key值存储对应的下标到`obj`
    - 排序`intervals`
    - 遍历排序后的`intervals` 以 每一项的第二个元素为`key` 以每一项的第一个元素为`index` 匹配当前元素的真实下标
    - 判断在obj中是否存在key 
        - 存在 `val = 目标区间的真实下标` 即存在目标区间的左界限 等于 当前区间的右界限
        - 不存在 `val = -1`
            - 二分法找到最近的右侧区间
3. 二分法找到最近的右侧区间  **注意left左移和right右移的判断条件**
    - 注意left左移和right右移的判断条件
    - `intervals[mid][0] < key` 表示不在左边直接移动left 缩小范围
    - `key < intervals[mid][0]` 表示在左边`更新val的值` 移动right 缩小范围查找更接近当前区间的右区间
    - 第三种情况是 不在当前的范围内 直接结束循环
4. 获取当前区间的真实坐标`obj[index]` 在 `result[obj[index]]` 中存入 `val`

```
var findRightInterval = function(intervals) {
    let len = intervals.length
    let left = -1
    let right = len
    let obj = {}
    while (left++ < right--) {
        obj[intervals[left][0]] = left
        obj[intervals[right][0]] = right
    }
    let j = 0
    let result = []
    intervals.sort((a, b) => a[0] - b[0])
    while (j < len) {
        let key = intervals[j][1]
        let index = intervals[j][0]
        let val = obj[key] ? obj[key] : (obj[key] === 0 ? 0 : -1)
        if (val === -1) {
            let left = 0
            let right = len - 1
            while (left <= right) {
                if(key == 14) console.log(left , right)
                let mid = Math.floor((left + right + 1) / 2)
                // key 在左边范围之外 不会出现
                if (intervals[mid][0] < key) { // key 不在左边
                    left = mid + 1
                } else if (key < intervals[mid][0]) { // key在右边范围
                    val = obj[intervals[mid][0]]
                    right = mid - 1
                } else {
                    break
                }
            }
        }
        result[obj[index]] = val
        j++
    }
    return result
};
```
