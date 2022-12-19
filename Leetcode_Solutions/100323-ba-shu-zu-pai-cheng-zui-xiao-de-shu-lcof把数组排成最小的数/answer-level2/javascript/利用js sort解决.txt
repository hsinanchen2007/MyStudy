### 解题思路
自定义sort compareFunction,快速获取结果。
![27C1BA29-4588-4CB9-A2A5-3203605134CE.png](https://pic.leetcode-cn.com/be6b85a7c0b64a4dae2ab2e6bef16b8daabf682a74aade225d190cc6c979c94e-27C1BA29-4588-4CB9-A2A5-3203605134CE.png)

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {string}
 */
var minNumber = function(nums) {
    return nums.sort((a, b) => {
        if(`${a}${b}` - `${b}${a}` > 0) {
            return 1;
        }else{
            return -1;
        }
    }).join('');
};
```