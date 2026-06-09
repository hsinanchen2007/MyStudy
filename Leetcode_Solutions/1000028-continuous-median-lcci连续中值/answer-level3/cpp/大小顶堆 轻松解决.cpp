c++中用greater<int> 的是小顶堆 small;
用less<int> 的是大顶堆 big;

但有趣的是 你需要保证小顶堆中的所有数字 必须大于 大顶堆中的所有数字。

所以呢 我们需要根据当前数字的大小决定放在大顶堆还是 小顶堆。

```
class MedianFinder {
	int cnt;
	priority_queue<int, vector<int>, greater<int>> small;
	priority_queue<int, vector<int>, less<int>> big;
public:
	/** initialize your data structure here. */
	MedianFinder() {
		cnt = 0;
	}

	void addNum(int num) {
		cnt++;
		if (!big.empty()) { 
			if (num > big.top()) small.push(num);
			else big.push(num);
		}
		else if (!small.empty()) {
			if (num > small.top()) small.push(num);
			else big.push(num);
		}
		else big.push(num);

		//平衡两个堆
		while (big.size() >= small.size() + 1) {
			small.push(big.top()); big.pop();
		}
		while (small.size() > big.size() + 1) {
			big.push(small.top()); small.pop();
		}
	}
	double findMedian() {
		
		if (cnt % 2) return small.top();
		else return (small.top() + big.top()) / 2.0f;
	}
};
```
