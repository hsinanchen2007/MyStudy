### 解题思路
![image.png](https://pic.leetcode-cn.com/444c7680cc6e4a44fd9618ab691271a65f08716723edb8044976704aef07c643-image.png)

- 先通过 map 进行遍历得到每个单独字符
- 通过叠加器 Reduce， 自动叠加在一起， 取~j 按位取反 进行判断;

### 代码

```javascript
/**
 * @param {string[]} A
 * @return {string[]}
 */
var commonChars = function (A) {
    // 将字符串转换成数组
    A = A.map(it => {
        return it.split('')
    })

    return A.reduce((pre, cur) => {
        let i = 0, arr = []
        while (pre && cur && i < pre.length) {
            let j = cur.indexOf(pre[i])
            if (~j) {
                arr.push(...cur.splice(j, 1))
            }
            i++
        }
        return arr
    })
};
```