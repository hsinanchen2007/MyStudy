### 解题思路
此题的思路和三数之和的思路是相同的，只是多了一个判断条件，详细解释见注释。
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ans;
        if(nums.size() < 4)  //如果数组的长度小于4，返回空数组
        return ans;
        sort(nums.begin(),nums.end());  //对数组进行排序
        int len = nums.size(), left, right, num;
        for(int i = 0; i < len - 3; i ++)  //指针i只能向右移动到len-4的位置
        if(i == 0 || nums[i] != nums[i - 1])  //排除相同解
        {
            for(int j = i + 1; j < len - 2; j ++)  //指针j只能向右移动到len-3的位置
            if(j == i + 1 || nums[j] != nums[j - 1])
            {
                left = j + 1;  //指针left指向j的下一个位置
                right = len - 1;  //指针right指向数组末尾
                while(left < right)
                {
                    num = nums[i] + nums[j] + nums[left] + nums[right];
                    if(num == target)
                    {
                        if(left == j + 1 || nums[left] != nums[left - 1])  //排除相同解
                        {
                            vector<int> outcome{nums[i],nums[j],nums[left],nums[right]};
                            ans.push_back(outcome);
                        }
                        left ++;
                        right --;
                    }
                    else if(num > target)
                    right --;
                    else
                    left ++;
                }
            }
        }
        return ans;
    }
};
```