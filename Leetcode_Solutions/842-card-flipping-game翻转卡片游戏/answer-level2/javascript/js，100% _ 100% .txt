简单捋一下，其实写个草稿很容易理解这个题目的意思。
首先就是遍历一遍过滤所有正反面都相同的牌，并且把值缓存起来
然后从正反面中找不存在缓存中的最小数字即可。
因为如果这个数字不存在于缓存中，那么只要把这个数字翻到背面，其他正面中与之相等的所有数字，都可以通过有限步去翻转到背面，并且由于他们的正反面都不同，所以不存在翻转之后不满足需求的情况

```
   /**
   * @param {number[]} fronts
   * @param {number[]} backs
   * @return {number}
   */
  var flipgame = function(fronts, backs) {
      let length = fronts.length,
          sameCache = {},
          min = Number.MAX_SAFE_INTEGER
    
      fronts.forEach((el, index) => 
          el === backs[index] && (sameCache[el] = true)
      )
    
      if (length === Object.keys(sameCache).length)  return 0
    
      fronts.concat(backs).forEach(el => {
          if (!sameCache[el] && el < min)  min = el
      })
    
      return min === Number.MAX_SAFE_INTEGER ? 0 : min
  };
```