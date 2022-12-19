
![QQ图片20200129165810.png](https://pic.leetcode-cn.com/caea20997a3d0bf310864c53ba8808c26592f3fe02b1ac5d7f2821e3ac8392bd-QQ%E5%9B%BE%E7%89%8720200129165810.png)

```js
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function (haystack, needle) {
    if (needle === "") {
        return 0;
    }
    // 对于小于needle.length的长度，可以不用遍历
    for (let i = 0; i < haystack.length - needle.length + 1; i++) {
        if (haystack[i] === needle[0]) {
            let isShoot = true;
            for (let k = 1; k < needle.length; k++) {
                if (needle[k] !== haystack[i + k]) {
                    isShoot = false;
                    break;
                }
            }
            // isShoot如果还是true，说明有匹配了
            if (isShoot) {
                return i;
            }
        }
    }
    return -1;
};
```
