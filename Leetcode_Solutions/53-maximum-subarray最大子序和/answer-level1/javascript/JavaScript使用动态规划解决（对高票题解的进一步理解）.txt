新手上路，脑袋都想破了[笑哭]

代码参考了高票题解的

高票题解的解释很好了，但是我还是理解了好一会，这里写下自己进一步的理解，作为高票题解的补充

1.如高票题解所说，为了能够复用之前的结果，我们在循环的以子序的最后一个元素作为循环元素
例如[a,b,c,d],我们算出a+b的话，a+b+c的时候就可以复用这一步的结果，而不用第二层循环

2.sum = Math.max( sum + nums[i], nums[i])
最大子序和 = 上次结果+当前元素 or 当前元素
这一步的代码保证了所求的子序是连续的，且计算值可以复用

3.result = Math.max( result, sum )
这句代码比较简单，就是保存最大值，因为sum在遍历的过程中并不一直保持最大

```
var maxSubArray = function(nums) {
    let result = nums[0]    //最终结果
    let sum = nums[0]       //每次找到的子序和
    for(let i = 1; i < nums.length; i++) {
        sum = Math.max( sum + nums[i], nums[i]) //获取几组子序和
        result = Math.max( result, sum )    //保存最大值
    }
    return result
};
```
