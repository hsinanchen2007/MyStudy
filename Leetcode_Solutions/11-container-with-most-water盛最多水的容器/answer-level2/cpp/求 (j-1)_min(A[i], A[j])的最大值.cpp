### 解题思路
该问题等价于：
给定一个数组A，设 i, j 为该数组的两个下标，求出 使得
(j-1)*min(A[i], A[j]) 的值
求解思路：初始化 i = 0, j = A.size()-1
从数组两端往中间收拢，每次计算完公式值后，根据选择高度较低的那个往中间靠拢。
时间复杂度：O(n), 空间复杂度 O(1)
 
### 代码

```cpp
class Solution {
public:

    int maxArea(vector<int>& height) {
        if(height.empty())  
            return 0;
        int result = 0;
        int i = 0, j = height.size()-1;
        while(i<j){
            int area = (j-i) * min(height[i], height[j]);
            if(area>result)
                result = area;
            if(height[i] < height[j] || (height[i]==height[j] && height[i+1] < height[j-1])){
                ++i;
            }else{
                --j;
            }
        }
        return result;
    }
};
```