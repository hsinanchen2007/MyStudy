

### 代码

```cpp
class Solution {
public:
/************************方法2：双指针*****************/
    int maxArea(vector<int>& height) {
        int max_area = 0,n = height.size();
        int start = 0,end = n-1;
        while(start < end)
        {
            max_area = max(min(height[start],height[end])*(end-start),max_area);
            height[start] < height[end] ? ++start:--end;  //将短边往长边一端移动
        }
        return max_area;
    }
};

/************************方法1：暴力********************
    int maxArea(vector<int>& height) {
        int max = 0;

        for(int i = 0; i < height.size(); i++)
        {
            int result = 0;
            for (int j = i + 1; j < height.size(); j++)
            {
                result = min(height[i],height[j]) * (j - i);
                if (max < result)
                {
                    max = result;
                }
            }
        }
        return max;
    }
*/
```