循环不变式，即 loop invariant，是循环迭代能够正确解决问题的「关键所在」。

每一个使用循环迭代解决问题的程序，都有一个或显式或隐式的「loop invariant」。

循环迭代能解决问题的核心：保证每一次子循环中的「loop invariant」。

-----

时刻记住：**循环不变式虽然是求解问题的关键，但循环不变式本身并不等同于问题答案**。

看到此题，应该联想到「斐波那契数列」，除非你之前没做过「斐波那契数列」问题。

每一步有两个选择：一步或者两步
换句话说：当前位置 `f(n)` 的前一个位置有两种可能：`f(n-1) or f(n-2)`

所以如果 `f(n)` 表示走到第 n 个台阶的可能路径，则有 `f(n) = f(n-1) + f(n-2)`

所以这个题的意思就是，爬上楼梯的所有路径中，路径和最小是多少。


对吧？**斐波那契数列。**

然后，开始寻找「循环不变式」相关的变量。

爬楼梯最小花费是指**爬过**所有楼梯，但中间过程都是**爬到某一个楼梯**，所以**过程**和**结果**有不一致性。

这里，我们做一个小小改动：**在末尾新增一节楼梯，花费为 0。** 

解题目标自然变为：爬到最后一节楼梯的最小花费。
中间迭代：爬到第 N 节楼梯的最小花费。

「循环不变式」相关的变量,对第 i 节楼梯:
- 爬到当前楼梯的最小花费 curMin
- 爬到此前楼梯的最小花费 preMin

代码如下：
```js
var minCostClimbingStairs = function(cost) {
  // smart trick
  cost.push(0)

  // initialize loop invariants related variables
  let preMin = curMin = 0
  // initialize next index
  let i = 0
  // iterate to update loop invariants related variables
  while (i < cost.length) {
    // update the preMin and curMin for current index i to ensure loop invariants
    [preMin, curMin] = [curMin, cost[i] + Math.min(preMin, curMin)]
    i++
  }
  // termination: answer is the curMin of index cost.lenght - 1
  console.assert(i == cost.length - 1)
  return curMin
};
```

携带「循环不变式」的递归版：
```js
var minCostClimbingStairs = function(cost) {
  // smart little trick
  cost.push(0)

  // initialize our two loop invariants related variables: preMin and curMin
  // and the next index: i 
  function loop(i = 0, preMin = 0, curMin = 0) {
    // check if we should terminate our loop
    if (i >= cost.length) return curMin
    // update our two loop invariants related variables, preMin and curMin, for current index i
    return loop(i + 1, curMin, cost[i] + Math.min(preMin, curMin))
  }

  return loop()
}
```

