

可以看成一只蜗牛爬台阶。
当这只蜗牛遇到上台阶的时候，啥事也不做，只往上上。
当它遇到要下去的台阶时，它会把尾巴伸出来，测量一下矩形面积，直到起点位置。
i就是蜗牛的位置，j是尾巴的位置。

当它伸尾巴的时候，它会比较从第i个位置的高度和第j个位置的高度中的最小值，并求出矩形面积。重复了i+1次。


```
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        if (heights.empty())
            return 0;
        if (heights.size() == 1)
            return heights[0];
        
        int i = 0;
        int res = heights[0];

        while(i < heights.size())
        {
            if(i < heights.size() - 1 && heights[i] <= heights[i+1])
            {
                ++i;
                continue;
            }
            
            int low = heights[i];
            
            for(int j = i; j >= 0; --j)
            {
                low = min(low, heights[j]);
                res = max((i-j+1)*low, res);
            }
            ++i;
        }
        return res;
    }
};
```
