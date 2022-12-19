### 解题思路
双指针：对于当前每个位置来说，只取决于一方，每次从高度较小的一方指针进行移动

### 代码

```cpp
class Solution {
public:
    //对于每个位置来说，当前的储水量只取决于两边高度较小的一侧
    int trap(vector<int>& height) {
        int len = height.size();
        if(len<=2) return 0;
        //双指针做法：首先使用两个指针指向数组两端，当左指针指向的高度大于右指针指向的高度时，从右指针一侧向左移动，而当左指针指向的高度小于右指针指向的高度时，从左指针一侧向右移动
        int l = 0 , r = len-1 , solve=0;
        while(l<r-1)
        {
            int index;
            if(height[l]<height[r]) {
                index = l+1;
                while(index<len && height[index]<height[l]) {
                    solve += (height[l]-height[index]);
                    index++;
                }
                l=index;
            }
            else {
                index = r-1;
                while(index>=0 && height[index]<height[r]) {
                    solve += (height[r]-height[index]);
                    index--;
                }
                r = index;
            }
        }
        return solve;
    }
};
```