Top K问题，用堆自然是最简单的想法
事件复杂度O(n*log k)
```cpp
class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto num: nums)
        {
            if(pq.size() < k)
            {
                pq.push(num);
            }
            else
            {
                if(num > pq.top())
                {
                    pq.pop();
                    pq.push(num);
                }
            }
        }
        return pq.top();
    }
};
```
类似于快速排序的快速选择法，实际上主要是利用了划分时每次可以确定一个下标在排好序之后的位置
时间复杂度O(n)
```cpp
class Solution
{
public:
	/*划分，返回下标*/
	int partition(vector<int>& nums, int left, int right)
	{
		int pivot = left;
		int p1 = left, p2 = left + 1;
		while (p2 <= right)
		{
			if (nums[p2] <= nums[pivot])
			{
				p1++;
				swap(nums[p1], nums[p2]);
			}
			p2++;
		}
		swap(nums[pivot], nums[p1]);
		return p1;
	}
	/*递归的快速选择算法，返回升序时下标为index的数字*/
	int quickChoose(vector<int>& nums, int left, int right, int index)
	{
		int mid = partition(nums, left, right);
		/*递归出口*/
		if (mid == index)
		{
			return nums[mid];
		}
		/*选择左一半递归*/
		else if (mid > index)
		{
			return quickChoose(nums, left, mid - 1, index);
		}
		/*选择右一半递归*/
		else
		{
			return quickChoose(nums, mid + 1, right, index);
		}
	}
	int findKthLargest(vector<int>& nums, int k)
	{
		int index = nums.size() - k;
		return quickChoose(nums, 0, nums.size() - 1, index);
	}
};
```