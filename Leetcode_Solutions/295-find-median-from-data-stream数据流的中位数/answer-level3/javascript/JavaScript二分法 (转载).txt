### 解题思路

我原本想要使用JS数组，通过记录堆的最大值和最小值的方式来模拟一个大顶堆和小顶堆，但是遇到了很多问题，就放弃了。但是发现在LeetCode英文版有一位用二分法来解题，很容易理解，现在分享一下：

如果用Java来实现的话，使用PriorityQueue应该是一个很好的选择，但是在JS中没有这种原生API，如果自己实现的话，代码就会变得非常复杂，比如在[LeetCode英文版](https://leetcode.com/problems/find-median-from-data-stream/discuss/329657/JavaScript-max-heap-%2B-min-heap)就有人自己撸了一个Heap来构建大顶堆和小顶堆，也是非常不错的。

但是在JS中操作数组非常方便，我们可以使用`Array.splice`这样的方法向数组的中间进行数据添加和删除。因此在JS中，二分法则成为了一个不错的选择：下面解法来自于[LeetCode英文版](https://leetcode.com/problems/find-median-from-data-stream/discuss/313652/Javascript-O(log-n)-%2B-O(1)-binarySearch-minHeap)的解题思路；

### 源码

```javascript
var MedianFinder = function() {
	this.arr = [];
};

MedianFinder.prototype.addNum = function(num) {
	const bs = (n) => {
		let start = 0;
		let end = this.arr.length;
		while (start < end) {
			let mid = (start + end) >> 1;
			if (n > this.arr[mid]) {
				start = mid + 1;
			} else {
				end = mid;
			}
		}
		this.arr.splice(start, 0, n);
	}

	if (this.arr.length === 0) {
		this.arr.push(num);
	} else {
		bs(num);
	}
};

MedianFinder.prototype.findMedian = function() {
	const mid = Math.floor(this.arr.length / 2);
	return (this.arr.length % 2 === 0) ? (this.arr[mid - 1] + this.arr[mid]) / 2 : this.arr[mid];
};

```
