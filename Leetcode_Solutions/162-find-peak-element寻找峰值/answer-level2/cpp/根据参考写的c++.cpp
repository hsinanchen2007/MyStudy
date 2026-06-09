### 解题思路
本质上是爬坡的思想，并不一定要找最高点，但找到点后一定是符合双边的判定

### 代码

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left<right){
            int mid = (left+right)/2;
            if(nums[mid]<nums[mid+1]){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
};//峰一定是在高处，根据点所在的曲率去选择爬坡的方向，根据需求筛选后做的点也满足逻辑筛选，二分法本质是把条件拆分了，通过二分范围逼近后得到同时满足条件的点
```