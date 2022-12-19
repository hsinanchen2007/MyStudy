### 解题思路
代码中每一步都有注释，一看就懂啦，不懂的评论即可~

### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let len = height.length;
    let res = 0;
    let max = 0;//当前最高峰

    for(let i = 0; i < len; i ++) {//遍历一遍height
        if(height[i] !== 0) {
            //此时的数x不为0的情况下，从前一位往前遍历，条件为小于最高峰，小于当前值x，j>=0
            for(let j = i - 1; height[j] < height[i] && height[j] < max && j >= 0; j --) {
            	let temp = (max > height[i]) ? height[i] - height[j] : max - height[j];//该位置水存储量
                res += temp;//结果+=
                height[j] += temp; //避免后续再遍历这个位置时二次加，所以把这里填上即可
            }
        }
        // max = Math.max(max, height[i]);
        if(max < height[i]) max = height[i];//更新max
    }
    return res;
};
```