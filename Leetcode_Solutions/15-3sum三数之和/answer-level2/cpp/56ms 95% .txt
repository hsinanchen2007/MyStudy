### 解题思路
排序后利用两数之和双指针解法思想构造a+b=-c。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ios::sync_with_stdio(false);
        vector<vector<int>> res;
        if(nums.size()<3)
            return res;
        sort(nums.begin(),nums.end());
        int target;
        int i,j,k=nums.size()-1;
        while(k>=2)
        {
            target = -nums[k];
            cout << target <<endl;
            i=0,j=k-1;
            //最小二数必须小于目标值 最大二数必须大于目标值 否则无解
            if(nums[0]+nums[1]<=target && nums[k-1]+nums[k-2]>=target)
            {
                //双指针遍历
                while(i<j)
                {
                    if(nums[i]+nums[j]<target) i++;
                    else if(nums[i]+nums[j]>target) j--;
                    else
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(-target);
                        res.push_back(temp);
                        while(i+1<j && nums[i+1]==nums[i])
                            i++;
                        while(j-1>i && nums[j-1]==nums[j])
                            j--;
                        i++;
                        j--;
                    }
                }

            }
            if(nums[k-1]==-target)
            {
                //避免重复删除所有等于target的数
                while(k>=0 && nums[k]==-target)
                    k--;
            }
            else
                k--;
        }
        return res;
    }
};
```