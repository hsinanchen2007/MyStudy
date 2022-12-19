### 解题思路
需要深入理解下快排, 归并, 堆, 桶等内容...

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(nums) {
    let arr = new Array(100000).fill(0)
    nums.forEach(num => {
        arr[num + 50000]++
    })
    let result = []
    arr.forEach((count, i) => {
        while(count){
            result.push(i - 50000)
            count--
        }
    })
    return result
};
```