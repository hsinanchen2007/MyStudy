### 解题思路
先将原数组排序，可知所有的差一定落在0与nums.back()-nums.front()中，在这里可以通过二分查找的方法来找到第k小的距离对：
即求得一个位于0与nums.back()-nums.front()之间的值mid，使得所有小于等于mid的距离对个数恰好为k。然后加一个统计小于某个值的距离对个数的函数作为判断二分的条件。

### 代码

```cpp
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.back()-nums.front();
        while(l<r){
            int mid=l+r>>1;
            if(getnum(nums,mid)>=k) r=mid;
            else l=mid+1;
        }
        return l;
    }
    int getnum(vector<int>& nums,int mid){
        int j=1,num=0;
        for(int i=0;i<nums.size();i++){
            while(j<nums.size()&&nums[j]-nums[i]<=mid){
                j++;
            }
            num+=j-i-1;
        }
        return num;
    }
};
```