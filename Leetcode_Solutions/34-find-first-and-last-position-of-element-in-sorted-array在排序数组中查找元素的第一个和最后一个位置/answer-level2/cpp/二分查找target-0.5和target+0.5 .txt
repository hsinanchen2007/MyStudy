### 解题思路
查找target，不妨转化为二分查找target-0.5和target+0.5，因为这两个数肯定不存在，所以跳出while循环时，left==right，此时比较nums[left]是否等于target，若相等，即为边界。
![屏幕快照 2020-03-23 下午10.22.26.png](https://pic.leetcode-cn.com/08625bd3252aacf94b9cbdd10a37a514e7300e70a6e8d0d435701c9cd4038075-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-23%20%E4%B8%8B%E5%8D%8810.22.26.png)
### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;int sz=nums.size();
        vector<int> no={-1,-1};
        if(sz==0 || nums[sz-1]<target || target<nums[0])
            return no;//排除target肯定不存在的情况
        double t1=target-0.5; double t2=target+0.5;
        int l=0,r=sz-1,mid;
        while(l<=r){
            mid=(l+r)>>1;
            if(nums[mid]>t1) r=mid-1;
            else l=mid+1;  
        } //二分查找target-0.5,即找到左边边界
        if(nums[l]==target)
            res.push_back(l);
        else return no;
        //压入左值（此时l==r,如果查到的nums[l]!=target,则说明target不存在，返回{-1,-1}

        l=0;r=sz-1;
        while(l<=r){
            mid=(l+r)>>1;
            if(nums[mid]>t2) r=mid-1;
            else l=mid+1; 
        }//二分查找target+0.5，即找到右边边界
        if(nums[l-1]==target)
            res.push_back(l-1);
        else return no;
    //压入左值（此时l==r,如果查到的nums[l-1]!=target,则说明target不存在，返回{-1,-1}；l-1不会溢出，因为开头已经排除sz==0的情况
        return res;
    }
};
```