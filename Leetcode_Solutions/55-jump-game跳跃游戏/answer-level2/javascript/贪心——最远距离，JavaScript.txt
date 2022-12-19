### 解题思路
思路都在代码注释中，代码不多，一看就会明白

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
    //换一种思路，计算出该路线能到的最远距离，判断最远的距离是否超过了该路径或者刚好到达终点
    //每一次都计算当前位置以及以前能走到的最远距离（贪心）
    let maxDistance = 0;
    const len = nums.length;
    for(let i = 0; i < len; i ++) {
        if(nums[i] === 0 && maxDistance <= i) break;//如果当前位置值为0，且当前能到达的最远距离还小于等于这个位置，那么它已经走不到后面了，直接退出循环就好了
        if(i + nums[i] > maxDistance) maxDistance = i + nums[i];
    }
    return maxDistance >= len- 1;


    //下面这种方法呢，其实我们浪费了很多计算资源，因为题目只需要直到是否能走到最后，不管你的路线是什么样，只要一个结果，能不能到。

    // greddy algorithms，贪心算法，总以当前最优的策略来处理问题，如果处理不了那么第二优策略来处理，直到所有策略都用过。本题中，肯定要跳当前能跳的最多步数来做，如果不可以则--（>0）。
    // const len = nums.length;
    // let res = false;
    // greddy(0);
    // return res;

    // function greddy(i) {
    //     if(i >= len - 1) res = true;
    //     if(nums[i] === 0) return;
    //     for(let j = nums[i]; j > 0; j --) {
    //         greddy(i + j);
    //     }
    // }
    //此算法计算大数据会超时
};
```