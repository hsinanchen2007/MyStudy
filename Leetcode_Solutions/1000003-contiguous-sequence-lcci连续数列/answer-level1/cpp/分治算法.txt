### 解题思路
最大值可能出现的地方有三处：
1、数列左边
2、数列右边
3、横跨数列左右两边

利用递归将数列无限分割成左右两边，直至只有一个数字；合并求最大子序列和。

### 代码

```cpp
class Solution {
public:
int subArraySum(vector<int>& nums, int left, int right){
    if(left == right)
        return nums[left];
    
    int mid = left + (right - left) / 2;
    int maxLeft = subArraySum(nums, left, mid);
    int maxRight = subArraySum(nums, mid + 1, right);
    
    int center = nums[mid] + nums[mid + 1];//横跨数列两边
    int maxMidLeft = center;//初始化左边数列的最大值为中间数
    int i = mid - 1;
    while(i >= left){//向左延伸，求横跨左右两边的最大子序列
        center += nums[i];
        maxMidLeft = max(maxMidLeft, center);
        i--;
    }
    
    int j = mid + 2;
    int maxMidRight = maxMidLeft;//初始化右边数列最大值为左边最大值
    while(j <= right){//向右延伸，求横跨左右两边的最大子序列
        maxMidLeft += nums[j];
        maxMidRight = max(maxMidRight, maxMidLeft);
        j++;
    }
    
    return max(maxLeft, max(maxRight, maxMidRight));//将三种情况的最大值返回
}


int maxSubArray(vector<int>& nums) {
    return subArraySum(nums, 0, nums.size() - 1);
}
};
```