### 解题思路
该题可以用贪心算法求解，但我看来也有点像穷举的方式。。。

### 代码

```javascript
/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var findContentChildren = function(g, s) {
    if(g.length === 0 || s.length === 0) return 0;
    const g_sort = g.sort((a,b) => a - b);       //将孩子胃口从小到大排序
    const s_sort = s.sort((a,b) => a - b);       //将饼干大小从小到大排序
    let gi = 0;si = 0;
    while(gi<g_sort.length && si<s_sort.length){        //开始的时候用的是两个for循环，但没有while好用。这里表示当遍历到最后一个孩子或最后一块饼干时结束
        if(g_sort[gi] <= s_sort[si]){                   //如果当前饼干能满足孩子，则看下一个孩子。由于已经是排序过的，当前饼干一定是满足当前孩子的最小饼干大小
            gi++                                        
        }
        si++                                            //不满足时看下一块饼干，满足时这块饼干已被消费，所以无论如何饼干数都递增
    }
    return gi;
};
```