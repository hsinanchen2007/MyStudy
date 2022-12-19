### 双指针法
单独考虑每一个位置i，这个地方水位的高度与左右两边较矮的那一边有关，因为最矮那一边决定了你能够装多少水。我们从数组的两端开始朝中间走，分别设置为left和right，每次我们都操作最矮的那一边，并记录其的left_max和right_max。
（1）如果当前位置处的height（left）或者height（right）大于了left_max或right_max，改变left_max或right_max的值，并继续走，因为当前位置更高，是装不下水的。
（2）否则，就用left_max或者right_max减去当前位置处的水位。
### 时间/空间
时间：O（n）
空间：O（1）
### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int left_max=0,right_max=0;
        int left=0,right=height.size()-1;
        int ans=0;
        while(left<right){
            if(height[left]<height[right]){
                height[left]>left_max ? (left_max=height[left]) : (ans+=left_max-height[left]);
                ++left;
            }else{
                height[right]>right_max ? (right_max=height[right]) : (ans+=right_max-height[right]);
                --right;
            }
        }
        return ans;
    }
};
```