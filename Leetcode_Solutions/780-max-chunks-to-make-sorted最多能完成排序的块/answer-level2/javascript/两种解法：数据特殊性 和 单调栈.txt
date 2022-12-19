## 自洽

由于数组元素的特殊性，即数组arr是[0, 1, ..., arr.length - 1]的一种排列，
可以推导出分割后的块中最大值 == 当前块的最右边元素下标，
能够分割成的块的个数 == 满足上述关系的最大值的个数。

```javascript
var maxChunksToSorted = function(arr) {
    if (arr.length == 0) return 0
    let counter = 0, max = arr[0]
    for (let i = 0; i < arr.length ; ++i){
        if (arr[i] > max) max = arr[i]
        if (max == i) counter++
    }
    return counter
};
```

## 单调递增栈

算法思路

根据题意，我们可以推导出任何 每一段序列的最小值和最大值 [min1, max1], [min2, max2], [min3, max3]...

满足关系 min1 < max1 < min2  < max2 < min3 < max3 < ...

我们可以定义栈结构，维护上面的数列关系，代码如下：

```javascript
/**
 * @param {number[]} arr
 * @return {number}
 */
var maxChunksToSorted = function(arr) {
    if (arr.length == 0) return 0
    let stack = []
    stack.push([arr[0], arr[0]])
    for (let i = 1; i< arr.length; i++){
        let cur = stack[stack.length - 1]
        // 判断三者大小关系 arr[i], cur[0], cur[1]
        if (arr[i] > cur[1]) {
            stack.push([arr[i], arr[i]])
        } else if (arr[i] < cur[0]){
            let max = cur[1]
            while (arr[i] < cur[0]){
                stack.pop()
                if (stack.length == 0){
                    stack.push([arr[i],max])
                    break
                }
                cur = stack[stack.length-1]
            }
            if (arr[i] > cur[1]){
                stack.push([arr[i],max])
            } else {
                stack.push([ stack.pop()[0], max])
            }
        }
    }
    return stack.length
};
```

欢迎关注[leetcode题解](https://github.com/muyids/leetcode)

推荐阅读

- [单调栈专题](https://github.com/muyids/leetcode/blob/master/tags/%E5%8D%95%E8%B0%83%E6%A0%88.md)

