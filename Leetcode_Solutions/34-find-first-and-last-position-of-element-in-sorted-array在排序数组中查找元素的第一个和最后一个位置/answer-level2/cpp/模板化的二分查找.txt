### 解题思路
这是道基础的二分查找题，我的这个代码有较为模板的二分查找，故发布

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> re;
        if(n==0){
            re.push_back(-1);
            re.push_back(-1);
            return re;
        }
        int l=0,r=n-1,mid;
        while(l<=r){
            mid=(r-l)/2+l;
            if(nums[mid]==target)break;
            else if(nums[mid]<target)l=mid+1;
            else r=mid-1;
        }

        if(nums[mid]!=target){
            re.push_back(-1);
            re.push_back(-1);
            return re;
        }

        l=r=mid;
        while(l>=0&&nums[l]==target){l--;}
        l++;
        while(r<n&&nums[r]==target){r++;}
        r--;

        re.push_back(l);
        re.push_back(r);

        return re;

    }
};
```