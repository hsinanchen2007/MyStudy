首先明确两点：1. 每个数组元素所在位置能接的雨水为：该元素两边峰值的较小者与该元素高度之差。累加即可。
             2. 从两头开始遍历，左峰较小的元素从左遍历，右峰较小的从右遍历。
```
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())  return 0;
        int left = 0;
        int right = height.size() - 1;
        int leftMax = height[0];
        int rightMax = height[height.size() - 1];
        int result = 0;
        while(left <= right){
            if(leftMax < rightMax){ //说明该元素积水高度取决于leftMax
                height[left] >= leftMax ? leftMax = height[left] : result += leftMax - height[left];
                left++;
            }  
            else{         //说明该元素积水高度取决于rightMax
                 height[right] >= rightMax ? rightMax = height[right] : result += rightMax - height[right];
                 right--;
            }
        }
        return result;
    }
};
```
