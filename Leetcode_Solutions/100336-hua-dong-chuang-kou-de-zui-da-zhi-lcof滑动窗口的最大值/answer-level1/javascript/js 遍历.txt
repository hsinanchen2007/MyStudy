### 解题思路
代码如下：

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function(nums, k) {
    if(nums.length===0)return [];
    let max=[];
    for(let i=0; i+k-1<nums.length;i++){
        let m=Math.max(...nums.slice(i,i+k));
        max.push(m);
    }
    return max;


};
```