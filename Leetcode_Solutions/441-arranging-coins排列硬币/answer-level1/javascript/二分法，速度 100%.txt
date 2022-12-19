### 思路
形成0行阶梯一共需要0个硬币，形成1行阶梯一共需要1个硬币，形成2行阶梯一共需要3个硬币，形成x行阶梯一共需要 1+2+...+x = (1+x)x/2个硬币。

换句话说，形成0、1、2、3……n 行阶梯需要的硬币数是 [0, 1, 3, 6, ...., (1+n)n/2]，可以看出是一个递增序列。现在题目问“有n个硬币时，能形成的完整阶梯行数”，抽象后就是“给你一个递增数组 nums，要求你返回 target 的位置，如果 target 不存在就返回距离 target 最近的左侧元素的位置”。

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var arrangeCoins = function(n) {
    if (n == 0) {
        return 0;
    }
    var left = 0;
    // 只有 n 个硬币的情况下，最大肯定不会超过 n 行，所以这里把搜索的右侧界限定为 n
    var right = n;
    while (left <= right) {
    	var mid = left + ((right - left) >> 1);
        // 形成 mid 行的阶梯一共需要 costToFinishMid 个硬币，这里是数学公式
    	var costToFinishMid = (1 + mid) * mid / 2;
    	if (costToFinishMid == n) {
    		return mid;
    	} else if (costToFinishMid < n) {
    		left = mid + 1;
    	} else if (costToFinishMid > n) {
    		right = mid - 1;
    	}
    }
    // 按照上述这种写法，right 在这里指向距离 target 最近的左侧元素的位置
    return right;
};
```