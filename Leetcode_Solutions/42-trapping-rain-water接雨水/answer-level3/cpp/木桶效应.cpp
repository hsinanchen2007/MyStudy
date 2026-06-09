### 解题思路
1. 从两边开始分别寻找高峰，左边的记为leftMax，右边的记为rightMax
2. 选取leftMax与rightMax中较低的一个，如果是leftMax，则高峰位置往后，低于leftMax的一定可以接水；如果是rightMax，则高峰位置往前，低于rightMax的一定可以接水
3. 第二步直到找到比高峰位置高的位置，此时返回第一步，从当前位置开始寻找高峰（上一次较高的高峰位置不动），找到后重复第二步
4. 以上，直到前后位置相遇，程序结束
没有用到任何数据结构，算法时间复杂度O(n)

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = 0;
        int rightMax = 0;
        int ans = 0;
        int i = 0, j = height.size() - 1;
        while(i < j){
            while(i < j && height[i] <= height[i+1]){
                ++i;
            }
            while(i < j && height[j] <= height[j-1]){
                --j;
            }
            leftMax = height[i];
            rightMax = height[j];
            if(leftMax < rightMax){
                while(i < j && height[i] <= leftMax){
                    ans += leftMax - height[i];
                    ++i;
                }
            }
            else{
                while(i < j && height[j] <= rightMax){
                    ans += rightMax - height[j];
                    --j;
                }
            }
        }
        return ans;
    }
};
```c
int trap(int* height, int heightSize){
    int leftMax = 0;
    int rightMax = 0;
    int ans = 0;
    int i = 0, j = heightSize - 1;
    while(i < j){
        while(i < j && height[i] <= height[i+1]){
            ++i;
        }
        while(i < j && height[j] <= height[j-1]){
            --j;
        }
        leftMax = height[i];
        rightMax = height[j];
        if(leftMax < rightMax){
            while(i < j && height[i] <= leftMax){
                ans += leftMax - height[i];
                ++i;
            }
        }
        else{
            while(i < j && height[j] <= rightMax){
                ans += rightMax - height[j];
                --j;
            }
        }
    }
    return ans;
}