### 解题思路
双指针法

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int sum = 0;
        int p = 0, q = height.size()-1;
        while(p<q){
            if(min(height[p],height[q])*(q-p) > sum)
                sum = min(height[p],height[q])*(q-p);
            if(height[p] < height[q]) p++;
            else  q--;
        }
        return sum;
    }
};
```