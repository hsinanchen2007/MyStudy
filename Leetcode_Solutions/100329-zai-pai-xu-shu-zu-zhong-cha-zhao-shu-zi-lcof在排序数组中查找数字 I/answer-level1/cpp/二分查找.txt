### 解题思路
二分查找

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<=j){
            int k=(i+j)/2;
            if(nums[k]==target){
                int x=k-1,y=k+1;
                while(x>=0&&nums[x]==target)
                    x--;
                while(y<nums.size()&&nums[y]==target)
                    y++;
                return y-x-1;
            }
            else
                if(nums[k]<target)
                    i=k+1;
                else
                    j=k-1;
        }
        return 0;
    }
};
```