### 解题思路
![image.png](https://pic.leetcode-cn.com/726a4ab13f2a0f915013e445a46e180f79be38fed25bd5d36e80419ac5ad1b5d-image.png)


排下序，头两个比一比

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var dominantIndex = function(nums) {
    let copy = nums.slice(0);
    copy.sort((a, b) => b - a);
    let max = copy[0];
    for (let i = 0; i < copy.length - 1; i++) {
        if (copy[i] != copy[i + 1]) {
            if (copy[i] / 2 < copy[i + 1]) {
                return -1;
            } else {
                break;
            }
        }
    }
    return nums.indexOf(max);
};
```