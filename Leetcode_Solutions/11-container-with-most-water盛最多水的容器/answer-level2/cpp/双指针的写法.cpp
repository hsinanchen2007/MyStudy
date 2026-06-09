### 解题思路
每次找出高度更小的边，然后减小底边的长度，这样面积才有可能增加。一直到左右指针相等为止

### 代码

```cpp
class Solution {
public:     
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, maxVal = 0;
        while(left < right){
            int flag = height[left] < height[right]? 1 : 0;
            if (flag){  //即左小
                maxVal = max((right - left) * height[left], maxVal);
                left++;
            }
            else{
                maxVal = max((right - left) * height[right], maxVal);
                right--;
            }
        }
        return maxVal;
    }
};
```