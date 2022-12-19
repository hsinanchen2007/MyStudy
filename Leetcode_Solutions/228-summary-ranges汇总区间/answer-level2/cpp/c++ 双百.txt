### 解题思路
![QQ图片20200313110124.png](https://pic.leetcode-cn.com/a15b43d762bd606917e84061fb6666de79d4e0dcc303a1f5378b4b63efb385a7-QQ%E5%9B%BE%E7%89%8720200313110124.png)


### 代码

```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string>ans;
        int left = 0;//双指针
        int right = 1;
        while(left < n)
        {
            if(right == n || (long)nums[right] - (long)nums[right - 1] != 1)//转换成long类型（防止INT_MIN -1溢出）
            {
                if(nums[left] == nums[right - 1])//无连续情况
                ans.push_back(to_string(nums[left]));
                else
                ans.push_back(to_string(nums[left])+"->"+to_string(nums[right-1]));//连续情况
                left = right; 
                if(right == n)
                break;
            }
            right++;   
        }
        return ans;
    }
};
```