头尾指针向中间逼近模板，类似的题都可套用，例如15,18题。

int pos1 = 0;
int pos2 = nums.size() - 1;
while (pos1<pos2) {
    //判断条件

    //pos更改条件
    if (nums[pos1]<nums[pos2])
        pos1++;
    else
        pos2--;
}

题解：
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int pos1 = 0;
		int pos2 = height.size() - 1;
		int max = 0;

		while (pos1 < pos2)
		{
			//判断条件
			int temp = min(height[pos1], height[pos2])*(pos2 - pos1);
			 //pos更改条件
			if(temp > max)
			{
				max = temp;
			}
				if (height[pos1] < height[pos2])
				{
					pos1++;
				}
				else
				{
					pos2--;
				}
		}
		return max;
	}
};