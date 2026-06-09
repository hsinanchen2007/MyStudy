### 解题思路
d[i]表示长度为i的末尾元素值，遍历一遍nums，遇到比当前d[len]元素大的就接在后面，否则就二分插入d[1~len]中的某个位置~

### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int k=nums.size();
        if(!k)return 0;
        vector<int>d;
        d.push_back(nums[0]);//表示长度i末尾元素值
        int len=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>d[len-1])d.push_back(nums[i]),len++;
            else
            {
                *lower_bound(d.begin(),d.end(),nums[i])=nums[i];
            }
        }
        return len;
    }
};
```