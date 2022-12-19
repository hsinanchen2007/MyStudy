### 解题思路
从实际角度考虑，假设现在最开始的i和最后的j围成面积是最大的。从两端到中间如果想要比现在的面积大，那么只可能比i和j更高。

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int _max = 0;
        int len = height.size();
        
        for (int i=0, j=len-1; i < j;) {
        	int s = (j - i) * min(height[i], height[j]);
        	if (_max < s) _max = s;
        	if (height[i] > height[j]) j--;
        	else i++;
        }
        
        return _max;
    }
};
```