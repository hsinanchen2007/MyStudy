
解题代码如下
```
/**
 * @param {number[]} arr
 * @return {boolean}
 */
var hasGroupsSizeX = function(arr) {
      let group = []
      let tmp = {}
      arr.forEach(item => {
        tmp[item] = tmp[item] ? tmp[item] + 1 : 1
      })
      for (let v of Object.values(tmp)) {
        group.push(v)
      }
      // 此时group已经存放的是每张牌的总数了（数组只遍历一遍，避免了排序和正则的耗时）
      // 求两个数的最大公约数
      let gcd = (a, b) => {
        if (b === 0) {
          return a
        } else {
          return gcd(b, a % b)
        }
      }
      while (group.length > 1) {
        let a = group.shift()
        let b = group.shift()
        let v = gcd(a, b)
        if (v === 1) {
          return false
        } else {
          group.unshift(v)
        }
      }
      return group.length ? group[0] > 1 : false
};
```
