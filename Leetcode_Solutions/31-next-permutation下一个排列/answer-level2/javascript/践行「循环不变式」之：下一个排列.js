循环不变式，即 loop invariant，是循环迭代能够正确解决问题的「关键所在」。

每一个使用循环迭代解决问题的程序，都有一个或显式或隐式的「loop invariant」。

循环迭代能解决问题的核心：保证每一次子循环中的「loop invariant」。

时刻记住：**循环不变式虽然是求解问题的关键，但循环不变式本身并不等同于问题答案**。


```js
var nextPermutation = function(nums) {
  // initialize start and end index
  // at last we will reverse range [start, end] of nums
  let start = 0, end = nums.length - 1

  function swap(i, j) {
    [nums[i], nums[j]] = [nums[j], nums[i]]
  }

  // initialize two loop invariant related variables: left and right
  // at last we maybe, just maybe call swap(left-1, right)
  let left = right = end

  // iterate to update left to ensure our loop invariant
  for (; left > 0; left--) {
    if (nums[left] > nums[left - 1]) break
  }

  // if next permutation is possible
  // we should iterate to update right to ensure our loop invariant 
  // and call swap(left-1, right)
  // and update start index
  if (left > 0) {
    for (; right >= left; right--) {
      if (nums[right] > nums[left - 1]) break
    }
    swap(left-1, right)
    start = left
  }

  // anyway, at last, we should do the reverse job
  let sum = start + end
  for (let i = start; i <= sum / 2; i++) {
    swap(i, sum - i)
  }
};
```
