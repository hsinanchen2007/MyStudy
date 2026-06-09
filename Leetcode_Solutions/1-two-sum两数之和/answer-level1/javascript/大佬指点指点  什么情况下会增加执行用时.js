### 解题思路
* 利用shift() 每次取出一个值 和数组进行对比

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
const twoSum = (nums, target) => {
    let len = nums.length;
    for (let i = 0; i < len; i++) {
        let o = nums.shift()
        let t = target - o;
        if (nums.indexOf(t) !== -1) {
            return [i, nums.indexOf(t) + i + 1]
        }
    }
};
```
