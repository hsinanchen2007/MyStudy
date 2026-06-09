循环不变式，即 loop invariant，是循环迭代能够正确解决问题的「关键所在」。

每一个使用循环迭代解决问题的程序，都有一个或显式或隐式的「loop invariant」。

循环迭代能解决问题的核心：保证每一次子循环中的「loop invariant」。

-----

时刻记住：**循环不变式虽然是求解问题的关键，但循环不变式本身并不等同于问题答案**。

这个题有一个切入点：**第 i 个元素只有抢或不抢两种选择。**

那么什么时候应该抢，什么时候不应该抢呢？

**如果把当前元素抢了，能够让最大金额增加，是不是应该抢一下？**

**但这并不是必然，因为暂时不抢当前元素，后续可能会有更大收益。**

那如果不抢当前元素，会造成什么后果呢？

**不抢的话，相当于重新开始，在之前能抢到的最大金额基础上重新开始。**

到这里，我们应该隐约意识到，我们必须维护至少两个「循环不变式」相关的变量：**迄今为止最大，以及迄今为止第二大。**

如果当前元素与迄今为止第二大元素相加大于迄今为止最大，则取而代之。迄今为止第二大就是旧的最大。
否则就不抢，而且不抢的话，迄今为止第二大也是旧的最大了。

循环之前初始化「循环不变式」相关的变量：`secondLargest = largest = 0`

循环过程中更新变量以确保「循环不变式」的依据：抢不抢当前元素 e
- 若 `secondLargest + e > largest: [secondLargest, largest] = [largest, secondLargest + e]`
- 否则：`secondLargest = largest = largest`，即回到开始状态

直到循环终止，循环不变式始终得到正确维护，答案为 `largest`。

```
var rob = function(nums) {
  // initialize loop invariant related variables before loop:
  let secondLargest = largest = 0

  for (let e of nums)
    // update secondLargest and largest: choose or not choose the current e
    // ensure our loop invariant 
    [secondLargest, largest] = [largest, Math.max(secondLargest + e, largest)]
  
  // termination: largest after the loop is our answer
  return largest
};
```

**这个题目，我之前尝试写能被接受的递归，一直没写出来，站在「循环不变式」的视角下，自然而然就出来了：**
```
var rob = function(nums) {
  function loop(i=-1, secondLargest=0, largest=0) {
    if (i === nums.length - 1) return largest
    return loop(i+1, largest, Math.max(largest, nums[i+1] + secondLargest))
  }
  return loop()
}
```

是的，这看上去似乎纯属多此一举，这个递归函数和循环根本没有区别好不好。嗯，我也意识到这一点了，我直接用 `loop` 命名了我的递归函数。

但我想说，这其中有**大微妙：递归版的实现是纯函数，没有任何 state 的修改。**

这其中涉及的东西还挺多的，此处略过不表。

