方法一： (O(n^2))暴力法：简单地考虑每对可能出现的线段组合并找出这些情况之下的最大面积。
```
class Solution
{
public:
	int maxArea(vector<int>& height)
	{
		int length;
		int heithtSize;
		int result=0;
		int temp = 0;
		for (int i = 0; i < height.size() - 1; ++i)
		{
			for (int j = i + 1; j < height.size(); ++j)
			{
				length = j - i;
				if (height[i] <= height[j])
					heithtSize = height[i];
				else
					heithtSize = height[j];
				temp = length * heithtSize;
				if (temp > result)
					result = temp;
			}
		}
		return result;
	}
};
```
方法二：(O(n))双指针法:最初我们考虑由最外围两条线段构成的区域。现在，为了使面积最大化，我们需要考虑更长的两条线段之间的区域。如果我们试图将指向较长线段的指针向内侧移动，矩形区域的面积将受限于较短的线段而不会获得任何增加。但是，在同样的条件下，移动指向较短线段的指针尽管造成了矩形宽度的减小，但却可能会有助于面积的增大。因为移动较短线段的指针会得到一条相对较长的线段，这可以克服由宽度减小而引起的面积减小。

```
//这个使用了系统函数max和min。需要包含头文件algorithm。。。
class Solution {
public:
    int maxArea(vector<int>& height) {
        int result=0;

        int leftIndex=0;
        int rightIndex=height.size()-1;

        int tempArea=0;
        
        while(leftIndex<rightIndex)
        {
            tempArea=(rightIndex-leftIndex)*min(height[leftIndex],height[rightIndex]);
            result=max(result,tempArea);

            if(height[leftIndex]<height[rightIndex])
            {
                leftIndex++;
            }
            else
            {
                rightIndex--;
            }

        }
        return result;
    }
};
```
