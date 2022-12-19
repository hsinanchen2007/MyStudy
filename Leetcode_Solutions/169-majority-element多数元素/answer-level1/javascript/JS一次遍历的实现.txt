思路：其实就是保存两个值，一个是count也就是次数，一个是数组中的数。
当我们遍历到下一个数字和之前保存的数字相同，count++,否则count--；
当count=0时，我们保存下一个数字。
```js
var majorityElement = function(nums) {
    let count = 1;
    let ans = nums[0];
    for(let i = 1; i < nums.length; ++i) {
        if(count === 0) {
            ans = nums[i];
            count = 1;
        }
        else if(nums[i] === ans) {
            ++count;
        } else 
            --count;
    }
    return ans;
};
```

![微信图片_20200114110650.png](https://pic.leetcode-cn.com/fcbbd1e066f80fdee39a2d418279ae4eb4e9073c88d2c208c41bdc89a69d330c-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200114110650.png)
