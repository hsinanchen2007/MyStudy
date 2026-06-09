### 解题思路
排序后用双指针。
其中用tmpP指向比low大1的最低位置
![image.png](https://pic.leetcode-cn.com/e3430ca5bd492f815d8876604f600a8663779019e6d9a52284f7dcbd70855960-image.png)

### 代码

```cpp
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int low=0,high=0;
        int res=0,tmpP=0;
        while(high<nums.size()){
            if(nums[high]==nums[low]+1)
            {
                if(tmpP==0)tmpP=high;
            }
            else if(nums[high]>nums[low]+1)
            {
                res=tmpP!=0 && res<high-low?high-low:res;
                if(tmpP==0)tmpP=high;
                low=tmpP;
                high=tmpP;
                tmpP=0;
            }
            high++;
        }
        return tmpP!=0 && res<high-low ? high-low : res;
    }
};
```