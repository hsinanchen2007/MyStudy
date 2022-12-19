击败 100%。

开辟一个哈希即可。

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    let map = {};
    for (let i = 0; i < nums.length; ++i) {
        map[nums[i]] ? map[nums[i]] ++ : map[nums[i]] = 1;
    }
    for (let key in map) {  
        if (map[key] >= 2) {
            return key;
        }
    }
};
```

![微信图片_20200211224130.png](https://pic.leetcode-cn.com/03d170e7011354e9fe6150253d70d032fe6ebbd42cbd24f5d933a54f02fb8beb-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200211224130.png)

