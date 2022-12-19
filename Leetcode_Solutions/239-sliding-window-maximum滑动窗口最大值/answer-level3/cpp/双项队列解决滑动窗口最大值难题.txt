这道题是从优先队列的难题里面找到的一个题目。可是解法并不是优先队列，而是双项队列`deque`

其实只要知道思路，这一道题直接写没有太大的问题。我们看看题



给定一个数组 $nums$，有一个大小为 $k$ 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口 $k$ 内的数字。滑动窗口每次只向右移动一位。

返回滑动窗口最大值。

**示例:**

```
输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```



翻译一下就是: 滑动区间里面每 $k$ 个最大值

当然暴力 naive 的解法就显而易见了，用 $O(n*k)$ 可以解决，不细说。但还是手痒写个伪代码:

```C++ []
for(size_t i=0;i<nums.size();i++){
    int maxValue=INT_MIN;
    for(size_t j=i;j<i+k;j++){
        maxValue=max(maxValue,nums[j]);
    }
    res.push_back(maxValue);
}
```

我想到的另一种方法是建立一个最大堆。

想法很简单：每次读入一个新的数字，就把不在区间范围内的数字移除堆里，然后堆的顶部就是此次循环的结果。

一个堆其实非常容易实现。我们甚至可以使用一个 `C++ STL` 中的 `priority_queue`。难点就在于，如何把这个不在区间范围内的数字移除。



### However

在这里我介绍一种更快更通用的方法，使用双项队列。这里为了效率和快捷使用了 `deque` 容器，也可以使用 `list` 容器。

我声明了一个变量 `deque<int>window`，用于存储下标。这个变量有以下 *特点*:

1. 变量的最前端（也就是 `window.front()`）是此次遍历的最大值的下标
2. 当我们遇到新的数时，将新的数和双项队列的末尾（也就是`window.back()`）比较，如果末尾比新数小，则把末尾扔掉，直到该队列的末尾比新数大或者队列为空的时候才停止，做法有点像使用栈进行括号匹配。
3. 双项队列中的所有值都要在窗口范围内

特点一只是方便我们获取每次窗口滑动一格之后的最大值，我们可以直接通过 `window.front()` 获得

通过特点二，可以保证队列里的元素是从头到尾降序的，由于队列里只有窗口内的数，所以他们其实就是窗口内第一大，第二大，第三大... 的数。

特点三就是根据题意设置的。但我们实际上只用比较现在的下标和 `window.front()` 就可以了，想想为什么？

**Answer：** 因为只要窗口内第一大元素也就是这个 `window.front()` 在窗口内，那我们可以不用管第二大第三大元素在不在区间内了。因为答案一定是这个第一大元素。如果 `window.front()` 不在窗口内，则将其弹出，第二个大元素变成第一大元素，第三大元素变成第二大元素以此类推。

代码编写的过程还要时刻检查队列是否为空防止抛出异常。

根据上面这些信息我们就可以编写此题的代码了。

### Solution

```C++ []
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==0)return {};
		vector<int>res;
		deque<size_t>window;
		/*Init K integers in the list*/
		for (size_t i = 0; i < k; i++) {
			while (!window.empty()  && nums[i] > nums[window.back()]) {
				window.pop_back();
			}
			window.push_back(i);
		}
		res.push_back(nums[window.front()]);
		/*End of initialization*/
		for (size_t i = k; i < nums.size(); i++) {
			if (!window.empty() && window.front() <= i - k) {
				window.pop_front();
			}
			while (!window.empty() && nums[i] > nums[window.back()]) {
				window.pop_back();
			}
			window.push_back(i);
			res.push_back(nums[window.front()]);
		}
		return res;
	}
};
```