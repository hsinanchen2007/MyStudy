### 解题思路
写了一个查找首次出现位置的函数和一个查找最后位置的函数，结构都差不多，使用二分查找的稍微变形，值得注意的是边界条件的判断
用时4ms, 内存8.3MB，内存消耗竟然击败了100%...

### 代码

```cpp
// 34. 在排序数组中查找元素的第一个和最后一个位置

# include <iostream>
# include <vector>

using namespace std;

int find_first_of(vector<int>& nums, int target){
    // 使用二分查找在最多log(n)的时间复杂度下找到第一个符合条件的下标
    int cnt = 1;
    if(nums.size()==0) return -1;
    int head=0, tail=nums.size()-1;
    int mid = (head + tail) / 2;
    while(tail > head){
        // cout << "第" << cnt << "次查询, " << "head=" << head 
        // << " mid=" << mid << " tail=" << tail << endl;
        if(nums[mid] >= target)
            tail = mid - 1;
        else
        {
            head = mid + 1;
        }
        mid = (head + tail) / 2;
        ++cnt;
    }

    // cout << "循环结束,第" << cnt << "次查询, " << "head=" << head 
    //     << " mid=" << mid << " tail=" << tail << endl;
    if (tail>=0&&(nums[tail]==target)){
        return tail;
    }
    else if(tail+1<nums.size() && nums[tail+1]==target)
        return tail+1;
    else
    {
        return -1;
    }
}

int find_end_of(vector<int>& nums, int target){
    // 使用二分查找在最多log(n)的时间复杂度下找到最后一个符合条件的下标
    int cnt = 1;
    if(nums.size()==0) return -1;
    int head=0, tail=nums.size()-1;
    int mid = (head + tail) / 2;
    while(tail > head){
        // cout << "第" << cnt << "次查询, " << "head=" << head 
        // << " mid=" << mid << " tail=" << tail << endl;
        if(nums[mid] > target)
            tail = mid - 1;
        else
        {
            head = mid + 1;
        }
        mid = (head + tail) / 2;
        ++cnt;
    }
    // cout << "循环结束,第" << cnt << "次查询, " << "head=" << head 
    //    << " mid=" << mid << " tail=" << tail << endl;
    if((head<nums.size())&&(nums[head]==target)){
        return head;
    }
    else if(head-1>=0 && nums[head-1]==target)
        return head-1;
    else
    {
        return -1;
    }
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> r(2);
        r[0] = find_first_of(nums, target);
        r[1] = find_end_of(nums, target);
        return r;
    }
};
```