单调栈分两类问题：

一种是从中间某一元素开始，求解此元素左右两边的最大或最小值
另一种求解整个序列，递增或递减子序列的最大跨度，此题为第二类

---

算法思路：

遍历一遍，生成一个单调递减栈，保存从左到右出现的最小值的下标

从右到左，查找比当前单减栈栈顶元素大的第一个数，更新最大跨度

```javascript
var maxWidthRamp = function(A) {
    let stack = [], max = 0
    stack.push(0)
    for (let i = 1; i< A.length; i++){
        if (A[stack[stack.length-1]] > A[i]) stack.push(i)
    }

    // 从右到左查找比栈顶元素大的第一个数
    for(let i = A.length -1; i >= max; i--){
        while (stack.length > 0 && A[i] >= A[stack[stack.length-1]]){
            max = Math.max(i-stack.pop(), max)
        }
    }
    return max
};
```

![962. 最大宽度坡 2019-12-07 18.17.36.png](https://pic.leetcode-cn.com/7195175fb832eebc8ce6c57b71fa1ec2cba161879803ff0845b07968797759d7-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-12-07%2018.17.36.png)

相似题目

- 1124.表现良好的最长时间段

欢迎关注[leetcode题解](https://github.com/muyids/leetcode)

推荐阅读

- [单调栈专题](https://github.com/muyids/leetcode/blob/master/tags/%E5%8D%95%E8%B0%83%E6%A0%88.md)
