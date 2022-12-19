### 解题思路
首先，确认肯定有一个最大值，以此为界分左右两边
然后明确计算的思路，确定当前遍历的高度cur，遍历的过程中记录小于当前高度的所有值的总和dump，然后划分出左右边界后(right-left-1)，
则当前这一段的可以积水的大小为：(right-left-1)*cur - dump
计算的流程是：先从左往右计算，如果最后一个最大值不在末尾，则在需要一次从右到最大值处的遍历。

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        //如果柱子数量小于1，那么肯定积不了水
        if(height.size()<=1) return 0;
        int ans = 0;
        //找到左边第一个非0元素
        int left = 0;
        while(height[left]==0) left++;
        
        while(left<height.size()){
            int right = left + 1;
            //记录当前高度
            int cur = height[left];
            //记录遍历过程中的“小”水柱的大小
            int dump = 0;
            //从左到右遍历，直到遇到没当前水柱高度小的水柱
            while(right<height.size() && height[right]<cur){
                dump += height[right];
                right ++;
            }
            //如果不是与边界形成的面积，那么就计算总积水量
            if(right<height.size()){
                //即当前围成的区域大小，减去被没过的水柱的面积
                ans += (right-left-1)*cur - dump;
                left = right;
            }else{
                break;
            }
        }
        int right = height.size()-1;
        while(height[right] == 0) right--;
        while(right>=left){
            int l2 = right-1;
            int cur = height[right];
            int dump = 0;
            while(l2>=left && height[l2]<cur){
                dump += height[l2];
                l2--;
            }
            if(l2>=left){
                ans += (right-l2-1)*cur - dump;
                right = l2;
            }else{
                break;
            }
        }
        return ans;
    }
};
/*

*/
```