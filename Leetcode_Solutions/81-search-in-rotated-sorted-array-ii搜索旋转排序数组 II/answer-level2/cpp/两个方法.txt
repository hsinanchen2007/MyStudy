对于不含重复元素的旋转数组的搜索，我们可以将时间复杂度压缩到 O(logn) 量级，但一旦存在重复元素，在极端情况下，会使得运行时间达到线性时间。（因为无法判断重复元素的部分在左侧还是在右侧）

方法一：线性查找。

遍历数组，寻找 target.

方法二：二分查找。

设置两个变量 left = 0, right = nums.size() - 1, 比较 nums[left] 与 nums[right] 的大小来决定下一步：
1. 若 nums[left] < nums[right], 此时没有发生旋转，按照一般的二分法处理即可；（见 noRotated 函数）
2. 若 nums[left] > nums[right], 此时一定发生了旋转，按照搜索旋转数组的二分法处理即可；（见 yesRotated 函数）
3. 若 nums[left] == nums[right], 这里就有一些纠结了，例如  [1,1,1,1,1,1,1], [1,1,1,1,1,3,1] 和 [1,3,1,1,1,1,1] , 无法区分旋转的区间到底是否发生了旋转，也无法区分旋转的区间在左侧还是右侧，此时，为了方便处理，可以将 left++, 这样处理可能到达极端情况，即退化为线性时间。

代码：
```cpp
class Solution {
public:
    void noRotated( vector<int>& nums, int& target, int& left, int& right, int& middle){    //没有旋转时二分
        if( nums[middle] > target)
            right = middle;
        else if( nums[middle] < target)
            left = middle + 1;
    }
    
    void yesRotated( vector<int>& nums, int& target, int& left, int& right, int& middle){    //旋转时二分
        if( nums[middle] <= nums[right]) // [middle, right]未旋转
            if( nums[middle] < target && nums[right] >= target)
                left = middle + 1;
            else
                right = middle;
        
        else   //[left, middle]未旋转
            if( nums[middle] > target && nums[left] <= target)
                right = middle;
            else
                left = middle + 1;
    }
    
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while( left < right){
            int middle = left + ( right - left)/2;
           // cout<<"left = "<<left<<" middle = "<<middle<<" right = "<<right<<endl;
            
            if( nums[middle] == target)
                return true;
            
            if(nums[left] < nums[right])   //未发生旋转
                noRotated( nums, target, left, right, middle);
            else if( nums[left] == nums[right]){    //可能发生旋转
                if( nums[middle] != nums[right])    //发生旋转
                    yesRotated( nums, target, left, right, middle);
                else    //[left, middle, right]  中至少有一侧发生旋转
                    left++; //此处影响了时间复杂度
            } 
            else if( nums[left] > nums[right])     //发生旋转
                yesRotated( nums, target, left, right, middle);
        }
        
        return left < nums.size() && nums[left] == target;
    }
};
```