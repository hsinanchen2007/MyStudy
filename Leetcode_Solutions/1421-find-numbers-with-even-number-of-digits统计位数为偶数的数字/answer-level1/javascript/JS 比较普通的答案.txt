### 解题思路
随着官方思路，将数字转换成文字放入数列计算长度后得出是否是偶数位加入计数器

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
    let even = 0
    for (let i =0 ; i< nums.length ; i++){
        let str = String(nums[i])
        let strArr = str.split('')
        if ( strArr.length%2==0) {
            even ++
        }
    }
    return even
};
```