直接排序是一种方法，但假如n远大于k，那么排序（即便是快速排序nlogn)仍有大量多余操作。
《方法一：堆》
可以维护一个大小为k的小顶堆，堆顶是最小值，遍历数组，当num大于堆顶时，加入堆，堆会自动调整，并将当前的最小值浮于堆顶。如果堆中元素个数大于K,删除堆顶（即当前堆的最小值），此后堆会自己调整，使得堆顶仍为最小值。调整堆时间复杂度为O(logk).总体时间复杂度为O(nlogk)，空间O(k)。注意，如果k非常接近n，那么转化成求第n-k+1小的数。C++可以使用优先队列作为堆，greater表示大于堆顶才入队，即小顶堆。
```
// Time O(nlogk) 12ms 82%, Space O(k)
class Solution {
	int findKthSmallest(vector<int> &nums, int k){
		priority_queue<int, vector<int>, less<int> > heap;
		for(const auto &num:nums){
			heap.push(num);
			if (heap.size()>k) heap.pop();
		}
		return heap.top();
	}
public:
	int findKthLargest(vector<int>& nums, int k) {
		int n=nums.size();
		if (n<k*2) return findKthSmallest(nums, n-k+1);
		priority_queue<int, vector<int>, greater<int> > heap;
		for(const auto &num:nums){
			heap.push(num);
			if (heap.size()>k) heap.pop();
		}
		return heap.top();
	}
};
```

《方法二：划分》
划分是将数组按照选定的key作为基准，大于key的放在后面，小于key的放在前面，最后返回key所在位置。这个位置就是整个数组排序后key值所在位置。进而可以直接返回第k小的数。注意，对于key的选择，一定要进行随机，否则会退化成O(n^2)。此题如果不进行随机选择，耗时30ms+。
```
// Time O(n) 8ms 98%, Space O(1)
class Solution {
    int partition(vector<int> &nums, int begin, int end){
        int i=begin, j=end-1, key;
        if (i>=j) return i;
        int keyid = begin+rand()%(end-begin);
        swap(nums[i], nums[keyid]);
        for(key=nums[i]; i<j;){
            for(; i<j && nums[j]>=key; --j);
            nums[i] = nums[j];
            for(; i<j && nums[i]<=key; ++i);
            nums[j] = nums[i];
        }
        nums[i] = key;
        return i;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size()-k;
        for(int i=0, j=nums.size(), p=-1; p!=k;){
            p = partition(nums, i, j);
            i = p<k ? p+1 : i;
            j = p<k ? j : p;
        }
        return nums[k];
    }
};
```