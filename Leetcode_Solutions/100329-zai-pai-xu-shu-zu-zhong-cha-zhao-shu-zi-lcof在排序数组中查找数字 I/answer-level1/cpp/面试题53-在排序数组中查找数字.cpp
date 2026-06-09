### 解题思路
emmm，我寻思常用算法里不就有个count么，好吧娱乐一下。面试的时候应该不让这么写吧，
正常思路：
- 排序数组很容易想到二分法；
- 关键是要找到第一个target和最后一个target；
- 因此在每次二分时加入比较，如果前一个不是target了返回为首位置，相应的有尾位置；
- 然后递归；
- 注意在判断前一个和后一个时不要越界。
### C++代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        int total = count(nums.begin(), nums.end(), target);
        return total;
    }
};
```
### 正常思路C++代码
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        int length = nums.size();
        int startIndex = findFirst(nums,0,length-1,target);
        int endIndex = findLast(nums,0,length-1,target);
        if(startIndex == -1 ||endIndex ==-1)
            return 0;
        else
            return endIndex-startIndex+1;
    }
    int findFirst(vector<int>& nums,int start,int end,int target)
    {
        if(start > end)
            return -1;
        int mid = (start+end)/2;
        int midData = nums[mid];
        if(midData == target)
        {
            if((mid>0 && nums[mid-1] !=target) || mid == 0)
            {
                return mid;
            }
            else
            {
                end = mid-1;
            }
        }
        else if(midData > target)
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
        return findFirst(nums,start,end,target);
    }
    int findLast(vector<int>& nums,int start,int end,int target)
    {
        if(start > end)
            return -1;
        int mid = (start+end)/2;
        int midData = nums[mid];
        if(midData == target)
        {
            if((mid<nums.size()-1 && nums[mid+1] !=target) || mid == nums.size()-1)
            {
                return mid;
            }
            else
            {
                start = mid+1;
            }
        }
        else if(midData > target)
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
        return findLast(nums,start,end,target);
    }
};
```
