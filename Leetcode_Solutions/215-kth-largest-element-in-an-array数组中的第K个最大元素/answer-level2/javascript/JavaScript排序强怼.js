### 解题思路
排序强怼系列，时间空间集体爆炸，但是过了hhh

回头再写个小顶堆

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findKthLargest = function(nums, k) {
    var arr=[];
    for (let i=0;i<k;i++){
        arr.push(nums[i])
    }
    arr.sort((a,b)=>(a-b))
    for (let i=k;i<nums.length;i++){
        arr.push(nums[i])
        arr.sort((a,b)=>(a-b))
        arr.shift()
    }
    return arr[0]
};
```