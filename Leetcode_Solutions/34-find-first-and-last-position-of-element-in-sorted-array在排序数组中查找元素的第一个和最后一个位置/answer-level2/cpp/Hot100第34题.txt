### 目前还是小白一个 就是提供一种想法 求轻喷
### 解题思路
看到排序找值的题且时间复杂度必须是 O(log n) 级别，基本上都是二分法变种题，所以肯定往二分法方向想。
第一步：先二分查找target值，如果数组中有和target值，那么常规二分后nums[mid] = target。例如在[1 3 3 3 5]中找3。二分直接找到nums[2] = 3。此时开始从数组的nums[2]处往左和往右分别查找是否还有和3相等的。
第二步：分情况讨论往左和往右找开始和结束位置
1. 先令start = mid，从中间往左找，如果nums[start] = target，start指针左移。要注意特殊情况，如果start = 0了且nums[start] = target，指针再左移start就变成-1了，此时nums[-1]会造成数组越界。所以要特殊处理。例如在[1 , 4]中找 4 应该输出start = 1，例如在[1 , 1]中找 1 应该输出start = 0 看代码我如何处理的，代码上有标记
2. 先令end = mid，从中间往右找，如果nums[end] = target，end指针右移。要注意特殊情况，如果end = size的话 nums[size]会造成数组越界

### 总结
就是常规二分稍微变形，然后想到找到target值就往左右找start和end就好了 处理好特殊情况（ps：特殊情况都是通过调试想到的）

### 运行结果
![image.png](https://pic.leetcode-cn.com/ff0d41ea40fe9cd53dfb5fe271a66edc60ee1f5cc1bd8558482040a654fa5bd9-image.png)

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return {-1,-1};
        if(nums.size() == 1)
            return nums[0] == target ? vector<int> {0,0} : vector<int> {-1,-1};
        int left = 0;   //定义二分左指针
        int right = nums.size() - 1;    //定义二分右指针
        int mid;    //定义中指针
        int start = -1; //用来存储找到目标值的开始位置
        int end = -1;   //用来存储找到目标值的结束位置
        while(left <= right) //二分查找
        {
            mid = left + (right - left) / 2;
            if(nums[mid] == target) //如果找到target 
            {
                //初始化开始位置和结束位置
                start = mid;
                end = mid;
                //开始从中间往左边找是否有和target相等的 有的话就让start左移 
                //且start为0 则退出 不加这个条件的话，下一次num[start = -1] 就会越界
                while(nums[start] == target && start != 0)
                    start--;
                //对start = 0特殊处理
                //例如在[1 , 4]中找 4  经过上一步 start = 0  应该输出1
                //例如在[1 , 1]中找 1  经过上一步 start = 0  应该输出0  
                if(nums[0] == target)
                    start = -1;
                //开始从中间往右边找是否有和target相等的 有的话就让start左移 
                //且end不能大于nums.size()-1 否则会越界
                while(nums[end] == target)
                {
                    end++;
                    //特殊情况 如果end = nums.size()应该跳出 否则越界
                    if(end == nums.size())
                        break;
                }
                //经过上述处理 就找到了开始和结束位置 输出即可
                return {start + 1 , end - 1};
            }
            if(target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        //如果没找到等于target的数 
        return {-1 , -1};

    }
};
```