### 解题思路
一边遍历一边存入新结果
完全小于newInterval -> 直接存入 -> 下一个位置
完全大于newInterval -> 先存入newInterval, flag = true, 再直接存入所有后续区间 -> 结束
更新newInterval的大小 -> 下一个位置
最后判断flag
flag = false -> 没有存入newInterval, 直接存入

### 代码

```javascript
/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function(intervals, newInterval) {
    let flag = false, result = []
    for(let i = 0; i < intervals.length; i++){
        if(intervals[i][1] < newInterval[0]){
            result.push(intervals[i])
            continue
        }
        if(intervals[i][0] > newInterval[1]){
            result.push(newInterval)
            flag = true
            for(let j = i; j < intervals.length; j++){
                result.push(intervals[j])
            }
            break
        }
        newInterval[0] = Math.min(newInterval[0], intervals[i][0])
        newInterval[1] = Math.max(newInterval[1], intervals[i][1])
    }
    if(!flag){
        result.push(newInterval)
    }
    return result
};
```