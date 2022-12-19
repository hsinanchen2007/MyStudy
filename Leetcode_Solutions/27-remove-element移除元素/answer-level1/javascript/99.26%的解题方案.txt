### 解题思路
思路一：逐个轮训，然后删除对应的val；但是会使用很多次splice，导致速度很慢；
### 代码
```javascript
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    let len = nums.length
    for (let i = 0; i < len;) {
        if (nums[i] === val) {
            len--
           nums.splice(i, 1)
        } else {
            i++
        }
    }
    return nums.length
};
```

思路二：为了减少使用splice，所以这边需要把val放到一起，这个时候排序是个好方法；先排序，然后找到val的下标，然后从val的下标开始循环;最后找到val出现的次数，最终一下子删除；
### 代码
```javascript
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    nums = nums.sort((val1, val2) => val1 - val2)
    let start = nums.indexOf(val)
    let i = start
    while (nums[i] === val) i++
    nums.splice(start, i - start)
    return nums.length
};
```

如下：
![image.png](https://pic.leetcode-cn.com/9410b5817fcfa3e709270c8e992e8cf8d9eb83c6f9233796e7717737dc989421-image.png)
