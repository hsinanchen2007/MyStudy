### 解题思路

果然还是大佬多呀
1、从右往左找到第一个右边大于左边的下标i(这样就代表当前组成的数字不是最大的)
2、然后呢，从第一个右边大于坐标的下标i这里往后找 最小的大于i-1下标的值，对调一下之后在i-1的这个位数上就是最小的了
3、把i之后（包括i）的所有值排序升序之后后面就是能组成的最小值了。
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function(nums) {
     for (let i = nums.length - 1; i > 0; i--) {
        // 找到符合下标i
        if (nums[i] > nums[i - 1]) {
            let min = nums[i];
            let k = i;
            // 查找后续最小的值的下标
            for (let j = i; j < nums.length ; j++) {
                //符合两个条件
                if (min > nums[j] && nums[i-1] < nums[j]) {
                    min = nums[j]
                    k = j
                }
            }
            // 对调
            [nums[i - 1], nums[k]] = [nums[k], nums[i - 1]];
            //拿到对调后的数组数据
            let newArr = nums.filter((item, key) => {
                return key >= i;
            })
            // 升序
            newArr.sort((a, b) => a - b)
            for (let m = 0; m < newArr.length; m++) {
                nums[i + m] = newArr[m]
            }
            return nums;
        }
    }
    // 没找到的话就是已经是最大值了，对调升序即可
    nums.sort((a, b) => a - b)
    return nums;
};
```