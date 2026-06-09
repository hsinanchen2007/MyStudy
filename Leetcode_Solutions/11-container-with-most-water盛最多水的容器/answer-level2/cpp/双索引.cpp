### 解题思路
1. 建立两个索引，
2. 分别从数组的两端向中间移动，找到最小的一端，进行移动操作
3. 计算面积
4. 记录面积最大的值，返回

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for (int i=0 ,j=height.size()-1;i < j ; ){
            int minheight = height[i] < height[j]?height[i++]:height[j--];
            int area = (j-i+1)*minheight;
            max  = max>area?max:area;
        }
        return max;
    }
};
```