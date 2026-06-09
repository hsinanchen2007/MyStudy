
循环不变式，即 loop invariant，是循环迭代能够正确解决问题的「关键所在」。

每一个使用循环迭代解决问题的程序，都有一个或显式或隐式的「loop invariant」。

循环迭代能解决问题的核心：保证每一次子循环中的「loop invariant」。

-----

时刻记住：**循环不变式虽然是求解问题的关键，但循环不变式本身并不等同于问题答案**。

跳跃游戏（一）要求解的问题是：能否从第一个位置跳到最后一个位置。

问题转化：把能否从第一个位置跳到最后一个位置的问题换成「能跳到最后一个位置的所有位置中，最靠左那个位置」，然后判断这个位置是否为第一个位置即可。

「循环不变式」相关的变量就是「当前已知最靠左的那个位置」。

循环开始之前，这个位置就是最后一个位置自己：`leftMost = nums.length - 1`

然后依次遍历 `[leftMost - 1, 0]`，并更新当前 `leftMost`，更新条件为 `i + nums[i] >= leftMost`

循环结束，判断 leftMost 是否为零即可。


```
var canJump = function(nums) {
  // initialize loop invariant related variable before loop
  // the left most postion which can jump to the end
  // well, the end itself must can
  let leftMost = nums.length - 1

  for (let i = leftMost - 1; i > -1; i--) {
    // check every postion from right to left
    // update leftMost to ensure loop invariant 
    // update the left most position which can jump to the end
    if (nums[i] + i >= leftMost) leftMost = i
  }

  // termination: check the leftMost result to get answer
  return leftMost === 0
};
```
