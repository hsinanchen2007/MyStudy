### 解题思路
&emsp;&emsp;题目的意思就是维护一个单调栈吧，保持栈底元素最大。有点类似[239.滑动窗口的最大值](https://leetcode-cn.com/problems/sliding-window-maximum/)只不过一个是用队列一个是栈，但本质都是维护最大值。我偷懒在栈里存了值和索引，可以和官方一样只存索引然后通过索引所以取值。

### 代码

```javascript
/**
 * @param {number[]} T
 * @return {number[]}
 */
var dailyTemperatures = function(T) {
    let res = new Array(T.length).fill(0),
        stack = [];
    for(let i = 0; i < T.length; i++){
        while(stack.length > 0 && stack[stack.length - 1][0] < T[i]){
            res[stack[stack.length - 1][1]] = i - stack[stack.length - 1][1];
            stack.pop();
        }
        stack.push([T[i], i]);
    }
    return res;
};
```