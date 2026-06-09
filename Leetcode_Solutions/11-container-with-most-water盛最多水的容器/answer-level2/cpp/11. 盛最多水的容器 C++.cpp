### 解题思路
1.利用双指针，数组首元素指针以及尾元素指针。
2.将不断计算两个指针所在划定的区域内容器容积，存放最大值，指针指向小的元素想指针指向大的元素靠近。
3.返回最大容积。

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0,l = 0,r = height.size() - 1;
        while(l < r){
            maxarea = max(maxarea,min(height[l],height[r])* (r - l));
            if(height[l] < height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxarea;
    }
};
```