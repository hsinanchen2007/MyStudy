### 解题思路
![image.png](https://pic.leetcode-cn.com/697a2f93cf4ada2d491f39529b378bc01ca5a093a042d8c6fa7a19d481b93f56-image.png)  

解题思路与最小重复数思路比较像：[最小重复数](https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-chang-gui-si-lu-tou-ji-qu-qi/)  

详细解答看下面注释
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
// 这道题用到了和寻找重复数中，比较相似的投机取巧；
// 利用可逆标记；
// 分三步：
// 第一步：寻找最小数是不是1,不是那么1就是解；这里还做了处理，将和题目不相符的，即小于1的数，全部标记为0
// 第二步：做可逆标记，这里用到的思想还是取反；但有个问题，就是计算位置如果是0，就比较难办，因为js中有-0的概念, 但ES6有一个新的
// API，Object.is(0, -0) === false；
// 第三步：遍历所有索引，遍历所有位置是不是都已被标记(有负号)，未被标记的第一个索引，就是最小的缺失整数；
// 以[3,4,-1,1]为例
var firstMissingPositive = function(nums) {
    let min = Number.MAX_SAFE_INTEGER;
    const length = nums.length;
    // 寻找最小数，并去除非相关数
    for(let i = 0; i< length; i++) {
        const target = nums[i];
        if (target > 0) {
            min = Math.min(min, target);
        } else {
            nums[i] = 0;
        }
    }
    if (min > 1) {
        return 1;
    }
    // 经过第一步变化后： nums: [3, 4, 0, 1];
    // 可逆标记，计算位置后，取反；
    for(let i = 0; i< length; i++) {
        // 该位置为0，则为非相关数，为a，则为已标记索引
        const target = Math.abs(nums[i]);
        if (target === 0) {
            continue;
        }
        let loc = target - 1;
        if (loc < length) {
            nums[loc] = -Math.abs(nums[loc]);
        }
    }
    // 经过第二步标记后： nums: [-3, 4, -0, -1];
    // console.log(nums);
    for(let i = 0; i< length; i++) {
        // 从上面就很容易看出，4所在的索引就是缺失的最小正整数
        if(nums[i] < 0 || Object.is(-0,nums[i])) {
            continue;
        }
        return 1 + i;
    }
    return length + 1;
};
```