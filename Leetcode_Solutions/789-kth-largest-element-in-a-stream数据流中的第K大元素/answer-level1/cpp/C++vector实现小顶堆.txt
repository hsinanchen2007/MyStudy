### 解题思路
堆结构，其实可以使用stl的优先级队列，这里使用了邓公版的向量实现小顶堆

### 代码

```cpp
	class KthLargest {
	public:
		KthLargest(int k, vector<int>& nums) {
			//排序+去重
			sort(nums.begin(), nums.end(), greater<int>());
			
			if(nums.size()>k)
				nums.erase(nums.begin()+k, nums.end());//删除自K往后的元素
			min_heap(nums);
			kk = k;
		}

		int add(int val) {
			
			//if (heap.size()>0&&val < getMin())
			//{
			//	return getMin();
			//}
			//else if(heap.size() > 0 && val > getMin())
			//{
			//	heap.erase(heap.begin());
			//	percolateUp(heap.size() - 1);
			//	insert(val);
			//	return getMin();
			//}
			//else if (heap.size() == 0)
			//{
			//	heap.push_back(val);
			//	return val;
			//}
			insert(val);
			if (heap.size() > kk)
				delMax();
			return getMin();

			//return getMin();
		}
		void min_heap(vector<int>& nums)
		{
			//建堆
			heap = nums;
			//自底向下 下滤内部节点
			for (int i = heap.size() - 1; i > -1; i--)
				percolateDown(i);

		}
		void insert(int val)
		{
			heap.push_back(val);
			percolateUp(heap.size() - 1);//上滤
		}
		void delMax()
		{
			swap(heap[0] , heap[heap.size() - 1]);
			heap.pop_back();
			percolateDown(0);
		}
		int getMin()
		{
			return heap[0];
		}
		int percolateDown(int i)
		{

			int j;
			while (i != (j = ProperParent(i)))
			{
				swap(heap[i], heap[j]);
				i = j;
			}
			return i;

		}
		int percolateUp(int i)
		{
			while (i > 0)//i只要有父亲
			{
				int j = (i - 1) >> 1;//i的父亲所在的位置
				if (heap[j] < heap[i]) break;//父子不逆序就上滤终止
				//否则父子交换位置，继续上滤
				swap(heap[j], heap[i]);
				i = j;
			}
			return i;
		}
		int ProperParent(int i)
		{
			int LC = 1 + ((i) << 1), RC = ((i)+1) << 1;
			int j;
			if (RC < heap.size())
			{
				j = heap[LC] <= heap[RC] ? LC : RC;
				j = heap[i] <= heap[j] ? i : j;

			}
			else if (LC < heap.size())
			{
				j = heap[i] <= heap[LC] ? i : LC;
			}
			else
			{
				j = i;
			}
			return j;
		}

	private:
		vector<int> heap;
		int kk;
	};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```