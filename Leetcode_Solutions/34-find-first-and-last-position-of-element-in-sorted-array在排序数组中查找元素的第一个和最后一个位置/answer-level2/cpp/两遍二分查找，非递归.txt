### 解题思路
![image.png](https://pic.leetcode-cn.com/38922dba04fe29e50e378e2f8af24ee0ed2f772f39de858267b438058e909740-image.png)

两遍二分查找，分别找最左端和最右端，只在当nums[mid]==target时做一些改变。
当然也可以用递归来找，递归时间短但是空间开销大。

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int n = nums.size();
        //考虑特殊情况
        if(n<1||nums[0]>target||nums[n-1]<target){
            res.push_back(-1);res.push_back(-1);
            return res;
        }
        if(nums[0]==target&&nums[n-1]==target){
            res.push_back(0);res.push_back(n-1);
            return res;
        }
        int l=0,r=n-1,m=(n-1)/2;
        int start=-1,end=-1;
        //找start
        while(l<=r){
            if(nums[m]==target){
                start=m;
                r=m-1;
            }else if(nums[m]<target){
                l=m+1;
            }else {
                r=m-1;
            }
            m=(l+r)/2;
        }
        l=0;r=n-1;m=(n-1)/2;
        //找end
        while(l<=r){
            if(nums[m]==target){
                end=m;
                l=m+1;
            }else if(nums[m]<target){
                l=m+1;
            }else {
                r=m-1;
            }
            m=(l+r)/2;
        }
        res.push_back(start);
        res.push_back(end);
        return res;
    }
};
```