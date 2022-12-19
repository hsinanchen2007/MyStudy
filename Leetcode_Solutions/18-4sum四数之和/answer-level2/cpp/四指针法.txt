### 解题思路
在前面三数之和得基础上再加一根指针

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int size = nums.size();
        if(size == 0)
        return ans;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<size-2;i++)
        {
          int tmp = nums[i];
           for( int start = i+1; start<size-2;start++)
           { int left  = start+1;
             int right = size-1;
             int val =target - tmp - nums[start];
            while(left < right)
            {
                int leftval = nums[left];
                int rightval = nums[right];
                int startval= nums[start];
                if(leftval + rightval == val)
                {
                    vector<int>vec{tmp,startval,leftval,rightval};
                    ans.push_back(vec);
                    while(left < right && nums[left] ==leftval)
                    {
                        left++;
                    }
                    while(left<right && nums[right] == rightval)
                    {
                        right --;
                    }
                }
                else if(leftval + rightval < val)
                {left ++ ;}
                else if(leftval + rightval > val)
                {
                    right--;
                }
            }
            while(nums[start] == nums[start+1] && start+1<size-2 )
                 start++;
             
    
            }
            while(i+1<size-3 && nums[i] == nums[i+1])
                i++;
        }

        return ans;
        }
};
```