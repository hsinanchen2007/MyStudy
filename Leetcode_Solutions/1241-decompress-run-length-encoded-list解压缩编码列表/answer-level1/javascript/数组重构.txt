### 解题思路
本不想写，但鉴于力扣还没有更新es7+的babel，还得自己写polyfill，所以顺便提一下。
1. 遍历元素，对2求模，映射一个新结对数组；
2. 对新结对数组再映射，map出数组长度和元素；
3. 平铺；

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
// polyfill
Array.prototype.flat = Array.prototype.flat || function() {
    return this.reduce((a,b) => a.concat(b))
}

var decompressRLElist = function(nums) {
    var arr = []
    nums.forEach((m,i) => {
        if(i%2===0){
            arr.push([m, nums[i+1]])
        }
    })
    arr = arr.map(m => Array(m[0]).fill(m[1]))
    return arr.flat()
};
```
### 复杂度
时间复杂度O(2n)，空间复杂度O(2n)