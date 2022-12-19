### 解题思路
先从大到小排排序,再取出第K大个. 此处下标是K-1

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findKthLargest = function(nums, k) {
    return( nums.sort(function(a,b){
        return b-a
    })[k-1])
};

```