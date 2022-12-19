### 解题思路
参考剑指offer的思路，要划分出中位数x，则左边均小于x，右边均大于x
因此通过堆，可以设置左边为最大堆，堆顶即是左边的最大值，右边设置最大堆，堆顶即是右边的最小值；
通过两个堆的总size，
如果为奇数，则为中间数字，该值我们存放在minHeap的top中
如果为偶数，则为中间两个数/2.0，即minHeap.top()+maxHeap.top()/2
大家如果不明白，可以用[2,3,4]和[2,3,4,5]两个例子来手动模拟一下添加的过程，这样能有更清晰的认识

### 代码

```cpp
class MedianFinder {
public:
	/** initialize your data structure here. */
	priority_queue<int,vector<int>,less<int>> maxHeap;//大顶堆
	priority_queue<int, vector<int>, greater<int>> minHeap;//小顶堆
	MedianFinder() {

	}
	void addNum(int num) {
		int size = maxHeap.size() + minHeap.size();
		/*
		为了保证数据平均分配到两个堆中，因此两个堆中数据的数目之差不能超过1
		因此可以假定总数目为偶数时，插入最小堆，否则插入最大堆
		如果当前总数目为偶数，插入最小堆
		*/
		if ((size&1)==0)//判断是否为偶数个
		{
			/*
				如果最大堆个数不为0
				且出现num比最大堆中的top还要小，如果直接插入最小堆(放到右边)
				是不行的，因为没有遵守右边均大于左边，因此要先插入到最大堆
				在最大堆中，取出top，再插入到最小堆
			*/
			if (maxHeap.size() > 0 && num < maxHeap.top()) {
				maxHeap.push(num);//入堆
				num = maxHeap.top();//去堆顶元素
				maxHeap.pop();//出堆
			}
			minHeap.push(num);//插入最小堆
		}
		//如果当前总数目为奇数，插入最大堆
		else
		{
			/*
				如果最小堆个数不为0
				且出现num比最小堆中的top还要大，如果直接插入最大堆(放到左边)
				是不行的，因为没有遵守左边均小于右边，因此要先插入到最小堆
				在最小堆中，取出top，再插入到最小堆
			*/
			if (minHeap.size()>0&&num> minHeap.top())
			{
				minHeap.push(num);
				num = minHeap.top();
				minHeap.pop();
			}
			maxHeap.push(num);//插入最大堆
		}
	}

	double findMedian() {
		int size = minHeap.size() + maxHeap.size();
		if (size == 0) return 0;//size为0
		if ((size&1))//判断是否为奇数个
		{
			return minHeap.top();
		}
		else//偶数
		{
			return (maxHeap.top() + minHeap.top()) / 2.0;
		}
	}
};
```