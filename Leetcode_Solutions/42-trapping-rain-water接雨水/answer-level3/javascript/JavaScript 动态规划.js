### 解题思路
求差：
雨水面积 = 所有面积和 - 柱子面积和；
用一个二维数组dp，dp[i][1]存储当前位置的所有面积和，dp[i][0]存储当前位置的柱子面积和；

柱子面积和很简单，累加就好了；
所有面积和则需要根据条件判断，有两种情况：
1.当前柱子是最大的那个，那么只需求得当前柱子和上一个最大柱子之间的所有面积和（可以看作一个矩形），然后累加上一个最大柱子的所有面积和。
2.当前柱子不是最大的那个，也就是说前面肯定有一个比它大的，那么需要找到第一个比它大的，然后思路和上面一样，求得两个柱子之间的所有面积和，即能得到当前面积总和；

遍历完成后，最后一个的差即为结果。

### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    if(height.length === 0) return 0;
    var dp = [];
    //当前最大柱子和柱子索引
    var max = height[0],maxindex = 0;
    //存放1.柱子面积 2.柱子面积+雨水面积
    dp[0] = [height[0],height[0]];
    for(var i = 1; i < height.length; i++){
        let curdp = [];
        //当前索引的所有柱子面积和
        curdp[0] = dp[i - 1][0] + height[i];
        //两种情况 1.当前柱子大于最大柱子 2.当前柱子小于最大柱子
        if(height[i] >= max){
            //求得当前柱子和雨水面积和。即只需重新计算两个最大柱子之间的面积，然后加上上一个最大柱子求得的柱子和雨水面积和。
            curdp[1] = Math.min(max,height[i]) * (i - maxindex) + dp[maxindex][1] + height[i] - max;
            max = height[i]; maxindex = i;
        }
        else{
            //找到第一个比当前柱子大的柱子，总会找到，因为它前面有一个最大的柱子
            for(var j = i - 1; j >= 0; j--){
                if(height[j] >= height[i]) break;
            }
            //思路前面类似
            let tmp = height[i] > height[j] ? (height[j] * (i-j) + height[i] - height[j]) : height[i]*(i-j);
            curdp[1] = tmp + dp[j][1];
        }
        dp[i] = curdp;
    }
    //求差，即为雨水面积
    return dp[height.length - 1][1] - dp[height.length - 1][0];
};
```