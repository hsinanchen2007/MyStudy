### 解题思路

题目说移动**两步**代价要**0**, 移动**一步**代价要**1**, 也就是说 **奇数移动到奇数要两步, 偶数移动到偶数也是两步**, 所以合并奇数无需代价, 合并偶数也无需代价

不管这个数组有什么数, 他要么是奇数要么是偶数

最终, 都可以零代价把他们都移动到两个位置上 , 一个是奇数, 一个是偶数, 然后看哪个数少, 我们就从少的移动到多的上面就行了


比如说 [1,2,2,3,3,4,6]

它最后都会回到这个问题上来:

               1   2
               3   2
               3   4
                   6 
--------------------------- 

这样很明显可以看出, 把奇数那一列移动到 偶数位置 代价最小

所以我们就筛选出数组的奇偶数, 判断哪个长度小,就取哪个.
              

### 代码

```javascript
/**
 * @param {number[]} chips
 * @return {number}
 */
var minCostToMoveChips = function(chips) {
    let odd = chips.filter(item=>item%2===1).length
    let even = chips.filter(item=>item%2===0).length

    return odd > even ? even : odd
};
```