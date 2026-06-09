### 解题思路
一开始写了个暴力法，二重循环，n^2复杂度，花费时间太长没通过测试。
然后自己理解了下题，发现最大的面积肯定是由短的那个决定，然后使用双指针lo和hi表示头尾，遍历直到他们相遇，哪个高度低，哪个指针前移一位，更新最大面积，直到lo与hi相遇

### 代码

```cpp
class Solution {
public:

    /*
    int maxArea(vector<int>& height) {//暴力法 n^2复杂度
       
        vector<int> area;
        int max=0;
        for(int i=0;i<height.size();i++)
            for(int j=0;j<height.size();j++)
            {
                int m=min(height[i],height[j])*(i>j?i-j:j-i);
                if(m>max)
                    max=m;
            }
        return max;
        */
   int maxArea(vector<int>& height)
   {
      int lo = 0, hi = height.size() - 1;//头尾指针
		int max = 0;//记录最大面积
		while (lo < hi)
		{
			
			int m = min(height[lo], height[hi])*(hi - lo);//本次的面积
			max = m > max ? m : max;
			if (height[lo] < height[hi])//哪边高度低哪边就前进一位
				lo++;
			else
				hi--;

		}
		return max;
   }
        
    
};
```