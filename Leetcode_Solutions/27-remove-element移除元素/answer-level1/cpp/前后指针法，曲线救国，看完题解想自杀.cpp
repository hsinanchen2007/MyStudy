### 解题思路
前后指针找 找到满足要求的元素 交换。很蠢

### 代码

```cpp
#include "iostream"
#include "vector"
#include "limits"
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==val) cnt++;
        }
        for(int j=0;j<nums.size();j++)
            {
                if(nums[j]==val)
                {
                    for(int k=nums.size()-1;k!=0;k--)
                    {
                        if(nums[k]!=val && nums[k]!=INT32_MAX && j<k)
                        {
                            nums[j]=nums[k];
                            nums[k]=INT32_MAX;
                            break;
                        }
                    }
                }
            }
        return nums.size()-cnt;
    }
};

```