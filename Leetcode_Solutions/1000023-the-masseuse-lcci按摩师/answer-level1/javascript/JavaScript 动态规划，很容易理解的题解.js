### 解题思路
本题中 面对每一个预约，我们有只有两种选择，选或者不选。
因此 我们定义变量dpy （yes）表示 选；定义dpn (no) 表示不选。
如果 目前这个预约我选了，那么之前那个预约一定是不选的， 所以 dpy = dpn + nums[i] 
如果 目前这个预约我不选，不选就意味着不存在，那么决定我当前dpn的值，肯定是上一次 选和不选 两个状态中的最大值。
所以 dpn = Math.max(dpy,dpn) 
### 代码

```javascript
var massage = function (nums) {
  if (nums.length === 0) return 0;
  let dpn = 0 // 不预约
  let dpy = nums[0] //预约
  for (let i = 1; i < nums.length; i++) {
    [dpn,dpy] = [Math.max(dpn,dpy),dpn+nums[i]]
  }
  return Math.max(dpn, dpy)
};
```
> 其实写动态规划的题目，有一点就是永远不要想太多，我当前的状态，只和我前一个有关，忘记其他的所有。

>[博客分享算法题和前端相关内容](http://lemonlife.top/)
> 部署在GitHub,访问可能有点慢