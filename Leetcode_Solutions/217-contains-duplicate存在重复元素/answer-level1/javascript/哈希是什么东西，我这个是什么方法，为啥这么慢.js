### 解题思路

![图片.png](https://pic.leetcode-cn.com/f97741ce08fcae52141dedd4835eee77349c38db5989dded98fd23988817bc6c-%E5%9B%BE%E7%89%87.png)
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    var stark = [];    // 创建一个空数组
    for (var i = 0; i < nums.length;i++){   //遍历给定的数组
        if(!stark.includes(nums[i])){       //如果数组里的值不在空数组里
            stark.push(nums[i])             // 就把那个值加到新建的stark这个空数组里 
        }else{
            return true                     // 如果在新建的数组里 那就是之前添加过同样的数说明前面有相同的数。那就返回true
        }
    }
    return false                             // 遍历完一直都没有相同的数那就是false咯
};
```