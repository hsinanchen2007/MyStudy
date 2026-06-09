将每个节点位置 i 最靠外的 左右两侧 不小于他的节点存在 left和right 中
用left 数组生成来说明：

i= 0 时，左边没有元素，left[i] = i；
当 heighst[i] > heigths[i-1] 时，那么他的最左侧 就是自己，left[i] = i;
当 heighst[i] == heights[i-1] 时，那么他们的最左侧显然是一样的， left[i]=left[i-1]
当 heights[i] < heigts[i-1] 的时候，稍微需要移动一下：
  位置 rank = heights[i-1]; rank 代表着 “最左侧，比heights[i]大的数的位置
  如果 rank-1 < 0 ，那么说名 rank是最外侧元素 , left[i] = rank;
  然后看 rank-1 > 0 合法的情况：
      如果 heights[rank-1] 的数，比hegihts[i] 小,那么就可以确定 left[i]的 最左元素是 rank ,直接 left[i]=rank；
      如果 heights[rank-1] 依然 比heights[i] 大，依然合法，
      那么我们就把 rank 挪动到 heights[rank] 的最左侧，继续用rank-1和 heights[i]比较，直到获得最终的 rank 

```
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
    if (heights.empty()) return 0;
	vector<int> left;
	vector<int> right(heights.size(),0);

	for (int i = 0; i < heights.size(); i++)
	{
		if (i == 0)
		{
			left.push_back(i);
			continue;
		}

		if (heights[i] == heights[i - 1])
			left.push_back(left[i - 1]);

		else if (heights[i] > heights[i - 1])
			left.push_back(i);

		else if(heights[i]<heights[i-1])
		{
			int rank = left[i - 1];
			while (rank - 1 >= 0 && heights[rank-1] >= heights[i])
			{
				rank = left[rank - 1];
			}
			left.push_back(rank);
		}
	}

	// 4  2  0  3  2  4  3  4
	// 0  0  0  3  3  5  5  7
	// 
	for (int i = heights.size() - 1; i >= 0; i--)
	{
		if (i == heights.size() - 1)
		{
			right[i] = i;
			continue;
		}

		if (heights[i] == heights[i + 1])
			right[i] = right[i + 1];
		else if (heights[i] > heights[i+1])
			right[i] = i;
		else if(heights[i] < heights[i+1])
		{
			int rank = right[i + 1];

			while (rank + 1 < heights.size() && heights[rank+1] >= heights[i])
				rank = right[rank + 1];
			right[i]=rank;
		}

	}

	int max = 0;
	for (int i = 0; i < heights.size(); i++)
	{
		int area = (right[i] - left[i] + 1) * heights[i];
		if (area > max) max = area;
	}

	return max;
    }
};
```
