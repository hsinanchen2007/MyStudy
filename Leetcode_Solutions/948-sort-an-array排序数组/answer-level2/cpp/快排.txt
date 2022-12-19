### 解题思路
快排思路：设定好中间点，使得左边的数小于等于它，右边的数大于等于它，在对其左右边进行重复即可

### 代码

```cpp
class Solution {
public:
	vector<int> narray;
	void quick_sort(int beg, int end)
	{
		if (beg >= end)
			return;
		//基准为narray[beg]
		int left = beg, right = end, base = narray[beg];
		while (left < right)
		{
			while (right > left)
			{
				if (narray[right] >= base)
				{
					right--; continue;
				}
				narray[left] = narray[right];
				break;
			}
			//找到左侧大于narray[base]
			while (left < right)
			{
				if (narray[left] <= base)
				{
					left++; continue;
				}
				narray[right] = narray[left];
				break;
			}

			if (left == right)
				narray[left] = base;


		}
		//对左右侧各进行一次快排
		quick_sort(beg, left-1);
		quick_sort(left + 1, end);

	}
	vector<int> sortArray(vector<int>& nums) {
	
		this->narray = nums;
		quick_sort(0, narray.size() - 1);
		return this->narray;
	}
};
```