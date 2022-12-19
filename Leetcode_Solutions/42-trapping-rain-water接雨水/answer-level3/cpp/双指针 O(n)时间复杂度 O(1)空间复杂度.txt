### 解题思路
这个题可以转变一下思路，不要去关注两个柱子中间可以存储多少水，要关注的是**每个柱子上能存多少水**。
那么每个柱子可以存储水的容量取决于什么呢？取决于柱子左边和右边是否有比他高的柱子。
因此我们需要两个指针记录此时左边和右边柱子的情况。
首先两个指针指向首尾，记做l和r，如果`height[l] < height[r]`，那么我们知道对于柱子l来说在它右边肯定有一个位置比它高，也就是r，因此此时我们只需要知道在l的左边有没有柱子比他高即可，也就是左边最高的柱子的高度（l_max）是否比它高，如果比他高，则该柱子上可以存储水，水的容量是`l_max - height[l]`，否则更新l_max即可，因为此时左边的柱子没有能拦得住它的。

这里可能会有个疑问：为什么存储水的容量是`l_max - height[l]`而不是`max(l_max,height[r]) - height[l]`呢，存储水的容量应该是由两个限制它边界的短板决定的呀？

这个问题其实能从我们的更新策略中看出来，我们每次更新的是较短的那一侧，也就是说如果指针此时指向的是l和r，那么其实在l之前柱子的高度都是小于r的高度的，同理r后的柱子的高度都是小于(等于)l柱子的高度的
### 出处
https://leetcode.com/problems/trapping-rain-water/discuss/17357/Sharing-my-simple-c%2B%2B-code%3A-O(n)-time-O(1)-space
### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
            return 0;
        int l = 0; // 记录当前左边位置
        int r = height.size() - 1; // 记录当前右边位置
        int result = 0; // 记录结果
        int l_max = 0; // 记录左边最高位置
        int r_max = 0; // 记录右边最高位置
        while(l < r){
            if(height[l] < height[r]){ 
                if(height[l] >= l_max)
                    l_max = height[l]; // 如果此时左边没有比他高的，此时不可能存水
                else
                    result += l_max - height[l];
                l++;
            }else{
                if(height[r] >= r_max)
                    r_max = height[r];
                else
                    result += r_max - height[r];

                r--;
            }

        }
        return result;        
    }
};
```