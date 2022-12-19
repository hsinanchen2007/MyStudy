### 解题思路
坦白的说，我是看了题解看明白的这道题，我写这个题解呢，不是为了炫耀我做出来了这道题，是希望能帮助到用js 的人，也帮助自己以后如果遇到类似的题可以过来看下自己当初是怎么做的，给自己一个思路。

为什么使用贪心算法呢，首先，我们不能直接求出问题的最优解，要分解成子问题逐个求解然后找到子问题的最优解。钱币找零问题呢，肯定是大面值的钱币优先考虑，所以我们肯定要将coins从大到小排序，然后先满足最大面值最多，然后找第二个面值。
这里有个奇葩的例子conins = [1,7,10],amount = 14，如果按照上面的方法，答案肯定是10 + 1 + 1 + 1 + 1，然而7 + 7肯定比上一个更优，所以，不管怎样我们一定要递归了所有可能的分配方法，然后找到其最优解，也就是整个问题的最优解了。

下面是代码注释：
- //在js中这里不能传入ans，因为js是按值传递的，传入的ans在函数内部无论如何更改变化，对外面的ans是没有关系的，所以索性直接使用外部的ans。
- //如果此时的总金额为0，就说明现在就是一个局部最优解
- //判断此时的最优解与全局最优解的关系，找到最优的存到ans
- //然后下面就没必要执行了，退回上一个函数然后k++找下一种情况就可以了
- //如果coins下标已经等于coins的len了，就说明这不是一种解，回退k++
- //这里仔细看能看明白，这里的k + count < ans条件很精髓，因为如果此时的面值数就已经大于ans了，那么接下来的比较都是多余的，这在一定程度上就优化了代码
### 代码

```javascript
/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function(coins, amount) {
    if(!amount) return 0;
    coins.sort((a,b) => b - a);
    let ans = Infinity;//最小面值数
    const coinsLen = coins.length;
    coinChange(amount, 0, 0);//当前总金额，当前coins的下标，当前面值数
    return ans === Infinity ? -1 : ans;

    function coinChange(amount, x_index, count) {//
        if(!amount) {//
            ans = Math.min(ans, count);//
            return;//
        }
        if(x_index === coinsLen) return;//
        
        for(let k = parseInt(amount / coins[x_index]); k >= 0 && k + count < ans; k --) {//
            coinChange(amount - k * coins[x_index], x_index + 1,count + k);
        }
    }
};
```