### 解题思路
for循环每一个数，先转换成字符串，长度%2，num++

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
    var nl = nums.length;
    var num = 0;
    for(let i = 0;i<nl;i++) {
        if(nums[i].toString().length % 2 == 0) {
            num++;
        }
    }
    return num;
};
```