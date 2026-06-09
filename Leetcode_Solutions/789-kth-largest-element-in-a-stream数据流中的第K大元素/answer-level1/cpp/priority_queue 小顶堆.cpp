### 解题思路
priority_queue维护了一个小顶堆，每次入队后自动排序。 保持队长为K，则队首就是题解。

### 代码

```cpp
// priority_queue 小顶堆
class KthLargest {
public:
	KthLargest(int k, vector<int>& nums) {
		this->k = k;
		for (int n : nums){
			add(n);
		}			
	}

	int add(int val) {
		pq.push(val);
		if (pq.size() > k){
			pq.pop();
		}
		return pq.top();
	}

private:
	priority_queue<int, vector<int>, greater<int>> pq;
	int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```