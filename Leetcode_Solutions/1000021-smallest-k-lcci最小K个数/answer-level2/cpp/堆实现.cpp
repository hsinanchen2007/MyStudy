```
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        for(auto num : arr)
        {
            insertHeap(num);
        }
        vector<int> ans;
        while(k--)
        {
            ans.push_back(getVal());
            deleteHeap();
        }
        return ans;
    }
	//插入
	void insertHeap(int val)
	{
		heap.push_back(val);
		seekUp(heap.size() - 1);
	}
	//删除
	void deleteHeap()
	{
		heap[0] = heap.back();
		heap.pop_back();
		seekDown(0);
	}
	//获取顶端的值
	int getVal()
	{
		if (heap.size() == 0) return -1;
		return heap[0];
	}
	//下沉
	void seekDown(int i)
	{
		while (i < heap.size())
		{
			int minIdx = i;
			int leftIdx = i * 2 + 1;
			int rightIdx = i * 2 + 2;
			if (leftIdx < heap.size() && heap[leftIdx] < heap[minIdx]) minIdx = leftIdx;
			if (rightIdx < heap.size() && heap[rightIdx] < heap[minIdx]) minIdx = rightIdx;
			if (minIdx != i)
			{
				swap(heap[minIdx], heap[i]);
				i = minIdx;
			}
			else return;
		}
	}
	//上浮
	void seekUp(int i)
	{
		while (i >= 0)
		{
			if (heap[i] < heap[(i - 1) / 2])
				swap(heap[i], heap[(i - 1) / 2]);
			else return;
			i = (i - 1) / 2;
		}
	}
	vector<int> heap;
};
```
