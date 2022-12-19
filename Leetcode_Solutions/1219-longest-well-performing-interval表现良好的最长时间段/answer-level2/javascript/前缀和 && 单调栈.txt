

## 前缀和

### 解题思路

定义一个前缀和数组，代表当前天以前所有工作时长 > 8小时的天数；
那么前缀和数组 两个元素的差 > 0 就是表现良好的时间段，我们只需要求得两个前缀和元素之差的最大值

```javascript
var longestWPI = function (hours) {
    let preSum = new Array(hours.length + 1).fill(0)
    for (let i = 1; i <= hours.length; i++) {
        if (hours[i-1] > 8) preSum[i] = preSum[i - 1] + 1
        else preSum[i] = preSum[i - 1] - 1
    }
    let max = 0
    for (let i = 0; i< preSum.length-1; i++){
        for (let j =i+1; j< preSum.length; j++){
            if (preSum[j] - preSum[i] >0){
                max = Math.max(max, j-i)
            }
        }
    }
    return max
};
```

## 前缀和 + 单调栈

### 解题思路

定义一个前缀和数组，代表当前天以前所有工作时长 > 8小时的天数；

求最长时间段，就是求上面前缀和数组前后元素满足关系 `i<j && preSum[i] < preSum[j]` 的最大跨度问题，类似题目962

求解方法：定义一个单调递减栈，保存从左到右出现的最小值的最左边下标；然后从右到左查找元素 > 单减栈栈顶，更新最大跨度；

```javascript
var longestWPI = function (hours) {
    // 前缀和
    let preSum = new Array(hours.length+1).fill(0)
    for (let i = 0; i < hours.length; i++) {
        if (hours[i] > 8) preSum[i+1] = preSum[i] + 1
        else preSum[i+1] = preSum[i] - 1
    }

    // 单减栈
    let stack = []
    stack.push(0)
    for (let i = 1; i < preSum.length; i++){
        if (preSum[stack[stack.length-1]] > preSum[i]) stack.push(i)
    }

    // 从右到左求最大跨度
    let max = 0
    for (let i = preSum.length-1; i > max; i--){
        while(stack.length > 0 && preSum[stack[stack.length-1]] < preSum[i]){
            max = Math.max(max, i - stack.pop() )
        }
    }
    return max
};
```