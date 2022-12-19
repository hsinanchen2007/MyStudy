### 解题思路
为求面积最大，即求左边(i)为0,1,..size-1的面积的最大值，只需要确定右边(j)即可。
右边从后往前找，只需要找到h[j]>=height[i]即可确定左边为i的最大值，因为j变小也不可能得到更大的面积

### 代码

```cpp
class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxA = 0;
		for (int i = 0; i < height.size(); i++)
		{
			//分别求出左边为i的各个最大值
			for (int j = height.size() - 1; j > i; j--)
			{
				if (height[j] >= height[i])
				{
					//此时面积为左边为i的最大,j减小不可能找到更大的面积
					int area = (j - i)*height[i];
					if (area > maxA)
						maxA = area;
					break;
				}

				int area = (j - i)*height[j];
				if (area > maxA)
					maxA = area;

			}
		}
		return maxA;
	}
};

```