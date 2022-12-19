### 解题思路
暴力解题，遍历数组，找到最大的max_area,计算公式：
max_area=max(min(y)*x)

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area=0;//初始化最大面积
        for(int i=0;i<height.size()-1;i++)//遍历到数组前一位
        {
            for(int j=i+1;j<height.size();j++)//从数组第二位开始遍历
            {
                int area=(j-i)*min(height[i],height[j]);//计算每次便利的面积
                if(area>max_area)
                {
                    max_area=area;//取每次面积最大值
                }

            }
        }
        return max_area;
    }
    
};
```