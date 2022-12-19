第一次正经写题解，我也不知道这种解法叫什么名字。
有一个人叫i，i被通知到的耗时 = i的上一级被通知到的耗时 + i的上一级要等多久才向下通知，这个应该很容易理解。
如果helper(i)返回值是**i被通知到的耗时**，那么 helper(i) = helper(i的管理员 也就是manager[i]) + infromTime[manager[i]];
理解了上面几句话，那就很简单了，只要用helper遍历整个manager数组，同时记录下最大的耗时，就是最终结果了。
直接看代码加注释：
```
/**
 * @param {number} n
 * @param {number} headID
 * @param {number[]} manager
 * @param {number[]} informTime
 * @return {number}
 */
var numOfMinutes = function (n, headID, manager, informTime) {
  if (n <= 1) return 0;
  const time = new Array(n); // time[i] 表示通知到i所花费的时间
  let ans = 0; // 最终结果

  // 遍历manager数组，从manager[0]开始递归，若time[i]有效则直接返回（记忆化），若manager[0]==-1则返回0（通知到最高管理员需要0时间）
  for (let i = 0; i < n; i++) {
    if (manager[i] === -1) time[i] = 0; // 若是管理员，则 通知到最高管理员耗时0
    else time[i] = helper(i); // 否则，需要helper(i)个时间

    ans = Math.max(ans, time[i]); // 取最大值，就是最后通知到的那个员工的耗时
  }

  return ans;

  //helper(i) 表示通知到i所花费的时间 比如helper(2)的返回值就是2被通知到的时间
  function helper(i) {
    if (time[i] >= 0) return time[i]; // 实现记忆化，若time[i]已经被计算过则直接返回
    else if (manager[i] === -1) { // 若是最高管理员，返回0
      time[i] = 0;
      return 0;
    }
    else return helper(manager[i]) + informTime[manager[i]];
    // helper(manager[i]) 就是通知到i的管理员要多久
    // informTime[manager[i]] 就是i的管理员要等多久才开始向下通知
    // [通知到i耗时] = [通知到i的管理员耗时] + [i的管理员要等多久才向下通知]
  }
};
```
