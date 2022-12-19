### 解题思路
![QQ图片20200115185021.png](https://pic.leetcode-cn.com/dea38090b4f5efa0d60c79f035314820aadf07f4f10dff6e4b9eeb493e909895-QQ%E5%9B%BE%E7%89%8720200115185021.png)

1. 先找出旋转点
2. 用两次二分查找
+ 旋转点前后都是有序序列
+ 旋转点为最小点
+ 应用二分查找获取最小值点。
  1. 由于该数组元素均不同，可发现若对数组nums[low,high]求mid ，若nums[mid]比最后的元素nums[high]小，证明右边有序，左边无序。
  2. 通过递归，最后会剩下两个数，无法解决，找规律发现右侧数为最小值。

### 代码

```cpp
class Solution {
public:

     int binary_search(vector<int> nums,int low,int high,int target)//二分查找
    {
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                low = mid+1;
            else
                high = mid-1;
        }
            return -1; 
    }

    int find_dot(vector<int>nums,int low,int high)  //找最小值点
    {
        if(low<high-1)  //剩下两个数
        {
            int mid =  (low+high)/2;
            if(nums[mid]<nums[high])//右侧有序
                return find_dot(nums,low,mid);
            else
                return find_dot(nums,mid,high);
        }
        else
            return high;
    }
    int search(vector<int>& nums, int target) {
    // 先搜索最小值点，两个二分法
    if(nums.size()==0)
        return -1;
    int dot = find_dot(nums,0,nums.size()-1);//找最小值点
    if(nums[dot]==target)
        return dot;
    else
    {
        int status = binary_search(nums,0,dot-1,target);//若已经能从一边找到就执行结束
        if(status!=-1)
            return status;
        else
            return binary_search(nums,dot+1,nums.size()-1,target);
    }
    }
        
};
```