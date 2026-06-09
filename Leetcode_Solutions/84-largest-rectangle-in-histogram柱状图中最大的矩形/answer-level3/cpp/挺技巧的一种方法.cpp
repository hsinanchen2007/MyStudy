跟42题接雨水那道题比较相似的解法
核心想法就是以某个柱子自身高为准，对这个柱子找左右两边第一个比它小的柱子
```
class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {

        if (heights.empty())
            return 0;
        if (heights.size() == 1)
            return heights[0];
        
        int n = heights.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        int res = 0;
        
        for( int i = 1; i <= n-1; i++) //left数组记录了某个柱子i的左边第一个比它低的柱子的位置
        {
            int p = i - 1;
            while(p >= 0 && heights[p] >= heights[i])
                p = left[p]; //用p--;也行，但增加了时间复杂度
            left[i] = p;
        }
        for( int i = n-2; i >= 0; i--) //right数组记录了某个柱子i的右边第一个比它低的柱子的位置
        {
            int p = i + 1;
            while(p <= n-1 && heights[p] >= heights[i])
                p = right[p];
            right[i] = p;
        }
        
        for( int i = 0; i < n; i++)
        {
            res = max(res, ((right[i]-left[i]-1) * heights[i]) ); //计算方法就是这个公式
        }
        return res;
    }
};

```
