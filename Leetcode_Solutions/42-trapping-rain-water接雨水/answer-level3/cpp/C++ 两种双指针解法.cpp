> 思路描述：这一题看起来倒是和maxArea有点类似，
>
> 如果逐次向右遍历，每次遇到比前一个最大值大的数，就可以先算出来改大数左边的面积，因为盛多少水取决于短板；左边界就变成这个大数，否则左边界不变。
>
> 但是这样会忽略掉一些情况，比如左边界右边的部分没有超过它的时候，这种时候从右向左遍历就好了。
>
> bingo！难得将近100%地做出来一道hard难度的题，我的时间复杂度其就是O(n)，准确点来说是3n，因为左右遍历一次，还有中间减的过程，当然也可以进一步优化。

```C++
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3) return 0;
        int max = 0, left = 0, right = height.size() - 1, area = 0;
        for(int i = 0; i < height.size(); i ++){
            if(height[i] == 0) continue;
            if(height[i] >= height[left]){
                if(i - left - 1 > 0){
                    area += min(height[i], height[left])*(i - left - 1);
                    for(int j = left + 1; j < i; j ++)
                        area -= height[j];
                }
                left = i;
            }
        }
        for(int i = height.size() - 1; i >= 0; i --){
            if(height[i] == 0) continue;
            if(height[i] > height[right]){
                if(right - i - 1 > 0){
                    area += min(height[i], height[right])*(right - i - 1);
                    for(int j = i + 1; j < right; j ++)
                        area -= height[j];
                }
                right = i;
            }
        }
        return area;
    }
};
```

> 双指针法非常巧妙，可惜没想到，这样也避免了我的算法重新再返回去减去一部分的值，这种解法其实是考虑每个小柱子能上升的最大水量，单独考虑，这种想法特别好。

```C++
class Solution {
public:
    int trap(vector<int>& height){
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            }
            else {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};
```

