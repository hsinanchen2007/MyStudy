### 解题思路
js中没有直接的hash表的API，所以要我们自己写一个hash表来用，写也非常简单，就一个{}。

思路：遍历nums数组，判断当前元素是否为hash的一个属性，如果是，则删掉这个属性（因为它重复了）；如果不是则添加以这个元素为属性名的属性。

最后输出hash的所有属性名即可~

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var singleNumbers = function(nums) {
    //hash
    let hash = {};
    let res = [];
    const len = nums.length;
    for(let i = 0; i < len; i ++) {
        if(hash[nums[i]] === undefined) {
            hash[nums[i]] = 1;
        } else {
            delete hash[nums[i]];
        }
    }
    for(let j in hash) {
        res.push(j);
    }
    return res;
};
```