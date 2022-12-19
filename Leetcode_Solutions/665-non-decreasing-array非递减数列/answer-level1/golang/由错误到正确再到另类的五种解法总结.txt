[原文](https://github.com/Shellbye/Shellbye.github.io/issues/86)
### 题目描述
```
给你一个长度为 n 的整数数组，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。

我们是这样定义一个非递减数列的： 对于数组中所有的 i (1 <= i < n)，总满足 array[i] <= array[i + 1]。

示例 1:
输入: nums = [4,2,3]
输出: true
解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。

示例 2:
输入: nums = [4,2,1]
输出: false
解释: 你不能在只改变一个元素的情况下将其变为非递减数列。

说明：

1 <= n <= 10 ^ 4
- 10 ^ 5 <= nums[i] <= 10 ^ 5
```

### 第一版的错误代码
根据题目描述，我们知道如果有两个以上的 `nums[i] > nums[i + 1]` 则意味着无法讲原数组通过改动一次变为非递减数列，所以我们可以在每次改动时判断并标记一个标记位，看看有没有改过，有就直接退出（返回 `false`），没有则改动之后继续。由以上思路，可以写出如下**不通过代码**:
```go
func checkPossibility(nums []int) bool {
	p := false
	for i := 0; i < len(nums) - 1; i++ {
		if nums[i] <= nums[i + 1] {
			continue
		} else {
			if p == true {
				return false
			}
			p = true
			nums[i] = nums[i + 1]
		}
	}
	return true
}
```
以上代码在遇到输入为 `[3,4,2,3]` 时就报错了，因为我们在进行改动时，使用单一的策略把当前位改成了与后一位相等，在以上输入场景中，`[3,2,2,3]` 也是不对的，而我们上面的代码却会返回 `true` 。出现这个问题的原因是我们在做改动时只考虑了当前位与后一位，而忽略了很重要的前一位。

### 第二版的错误代码
既然在上面的场景中，我们分析到了错误的位置，那么马上我们就可以通过补上这个漏洞再来一版（错误的解答）：
```go
func checkPossibility(nums []int) bool {
	p := false
	for i := 0; i < len(nums) - 1; i++ {

		if nums[i] <= nums[i + 1] {
			continue
		} else {
			if p == true {
				return false
			}
			p = true
			nums[i] = nums[i + 1]
			if i > 0 && nums[i] < nums[i-1] {
				return false
			}
		}
	}
	return true
}
```
这一版本我们修复了上一个版本的问题，但是它依然是有问题的，它在遇到 `[2,3,3,2,4]` 的时候还是返回了错误的答案。按照我们的代码，我们把第二个 `3` 要改成 `2` ，但是却发现它改动之后小于前面的数（即第一个 `3`），所以我们返回了 `false` ，但是其实我们可以通过把第二个 `2` 改为 `3` 来完成一次改动即为非递减数列的操作。那么这次的问题彻底让我们知道了，只改当前数字（本例中是第二个 `3`）是不行的，我们还得看看前后的数，也有可能会改动他们。

### 第三版的正确解法
经历了上面几次的碰壁之后，我们终于可以仔细的整理一下思路，写出来正确的解答了：
```go
func checkPossibility(nums []int) bool {
	if len(nums) < 3 {
		return true
	}
	p := false
	// 第 0 个的处理比较特殊，因为它不需要照顾前面的数，所以直接改小自己就行
	if nums[0] > nums[1] {
		nums[0] = nums[1]
		p = true
	}
	for i := 1; i < len(nums)-1; i++ {
		// 当前数大于后一个数，破坏了非递减
		if nums[i] > nums[i+1]{
			if p {
				return false
			}
			p = true
			// 改动时，要 nums[i] 变小还是 nums[i+1] 变大需要做一个判断
			// nums[i] 和 nums[i-1] 的关系是确定的， nums[i] >= nums[i - 1]
			// nums[i] 也大于 nums[i + 1]，现在需要确定 nums[i + 1] 和 nums[i - 1] 的关系
			// 如果nums[ i + 1] 大于 nums[i - 1]，则调小 nums[i] 和 调大 nums[i + 1] 都行
			// 但是这里还是要优先调小 nums[i]，因为 nums[i + 1] 大了更不利于非减的要求，它可能大于后面的数了
			// 如果 nums[i + 1] 小于 nums[i - 1]，则必须调大 nums[i + 1]
			if nums[i+1] >= nums[i-1] {
				nums[i] = nums[i-1]
			} else {
				nums[i+1] = nums[i]
			}
		}
	}
	return true
}
```

### 第四版的另类解法
我们上面的解法，是完全顺着题目的描述思路来进行的，发现有递减出现的时候也按照题目要求进行了改动。我查了一些[资料](https://leetcode.com/problems/non-decreasing-array/solution/)，发现是有一些思路比较另类的解法，可以贴出来学习一下。
```go
func checkPossibility(nums []int) bool {
	p := -1
	for i := 0; i < len(nums)-1; i++ {
		if nums[i] > nums[i+1] {
			if p != -1 {
				return false
			}
			p = i
		}
	}
	return p == -1 || p == 0 || p == len(nums)-2 || nums[p-1] <= nums[p+1] || nums[p] <= nums[p+2]
}
```
这个代码逻辑基本都集中在最后一行了，上面的 `for` 循环基本就干了一件事：判断是否最多只有一组逆序对。判断结束之后就是对结果分条件执行了：
1. `p == -1` ：没有逆序，返回 `true`
2. `p == 0` ：逆序出现在第一组，第一个数改为最小（或相等）即可，返回 `true`
3. `p == len(nums)-2` ：逆序出现在最后一组，最后一个数改为最大（或相等）即可，返回 `true`
4. `nums[p-1] <= nums[p+1]` ：逆序组存在，而且前一位小于等于后一位，可以通过调小 `nums[i]` 来完成非递减的工作，最终满足 `nums[p-1] <= nums[p] <= nums[p+1]`
5. `nums[p] <= nums[p+2]` ：逆序组存在，而且当前位小于等于后一位的后一位，可以通过调大 `nums[i+1]` 来完成非递减的工作，最终满足 `nums[p] <= nums[p+1] <= nums[p+2]`

### 第五版的另类解法
这个解法是从一篇[博客](https://blog.csdn.net/qq_16151925/article/details/80204834)中看到的，与上面的思路都不一样。大体思路就是从头和尾分别开始往中间找符合非递减的队列，那么两边最终都会在某一个逆序的地方停住（或者是多个，那就不行了），停住之后，如果两个队列中间只隔了一个数字，且这两个队列的最大和最小值也整体符合全局的非递减，那么就可以返回 `true` 。
```go
func checkPossibility(nums []int) bool {
	i := 0
	j := len(nums) - 1
	for ; i < j && nums[i] <= nums[i+1]; {
		i++
	}
	for ; i < j && nums[j] >= nums[j-1]; {
		j--
	}

	head := -100000
	if i != 0 {
		head = nums[i-1]
	}
	tail := 100000
	if j != len(nums)-1 {
		tail = nums[j+1]
	}

	if j-i <= 1 && (head <= nums[j] || tail >= nums[i]) {
		return true
	} else {
		return false
	}
}
```
