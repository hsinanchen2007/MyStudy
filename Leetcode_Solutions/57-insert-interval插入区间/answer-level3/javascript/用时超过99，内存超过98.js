#### 转换为区间合并问题

```
var insert = function (intervals, newInterval) {
    intervals.push(newInterval)
    intervals.sort((a, b) => {
        return a[0] - b[0]
    })
    let arr = []
    arr.push(intervals.reduce((acc, cur) => {
        if (acc[1] >= cur[0]) {
            cur[0] = acc[0]
            cur[1] = Math.max(acc[1], cur[1])
        } else {
            arr.push(acc)
        }
        return cur
    }))
    return arr
};
```
代码看着挺简洁的，但是效率并不高，intervals是排好序的，插入数据再排序花费很多时间
![微信截图_20200321175611.png](https://pic.leetcode-cn.com/a2c8ab3f9da8ad5d5785308551ba357c0cf0e6bc1c05b6b1d253dbc72063ac28-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200321175611.png)


#### 双指针硬解

```
var insert = function (intervals, newInterval) {
    if (intervals.length == 0) return [newInterval]
    let minNum = intervals[0][0],
        maxNum = intervals[intervals.length - 1][1]
    if (newInterval[1] < minNum) {
        intervals.unshift(newInterval)
        return intervals
    }
    if (newInterval[0] > maxNum) {
        intervals.push(newInterval)
        return intervals
    }

    let cursL = 0,
        cursR = 0

    for (let i = 0; i < intervals.length; i++) {
        if (intervals[i][1] >= newInterval[0]) {
            cursL = i
            break
        }
    }
    for (let i = intervals.length - 1; i >= 0; i--) {
        if (intervals[i][0] <= newInterval[1]) {
            cursR = i
            break
        }
    }

    return Array.prototype.concat(intervals.slice(0, cursL),
        [
            [Math.min(intervals[cursL][0], newInterval[0]), Math.max(intervals[cursR][1], newInterval[1])]
        ],
        intervals.slice(cursR + 1))
};
```
用两个指针找到插入数组和原数组相交的位置，处理得到结果，冒泡思想
![微信截图_20200321175920.png](https://pic.leetcode-cn.com/b62271fa8e97a0fdcb123fedbaac83b2e6b99942dd524112375f5988dca8b5ef-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200321175920.png)

被hard难度吓到了

