### 解题思路
1. 根据原数组得出一个新数组，每项只包含原数组的索引值和第一项
2. 把新数组排序
3. 根据新数组对原数组的每一项二分判断

### 代码

```javascript
/**
 * @param {number[][]} intervals
 * @return {number[]}
 */
var findRightInterval = function (intervals) {
    
    let sortedData = intervals.map((item,index) => {
        return {
            index,
            val:item[0]
        }
    }).sort((a,b)=>a.val-b.val)
    let result = []
    
    for (let i = 0; i < intervals.length; i++) {
        let first = intervals[i][1]
        let low = 0;
        let high = intervals.length
        while (low < high) {
            let mid = low + Math.floor((high - low) / 2)
            let second = sortedData[mid].val
            if (second>= first) {
                high = mid
            } else {
                low = mid + 1
            }
        }
        
        result.push(sortedData[low] === undefined ? -1 : sortedData[low].index)
    }
    return result
};

```