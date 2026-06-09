### 解题思路
此处撰写解题思路
一共只有0 1 2三种数字，对其进行计数即可，有则填上，无则跳过
### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num[3]={0,0,0};
        for(int i=0;i<nums.size();i++)
        {
            num[nums[i]]++;
        }
        int j=0;
        for(int i=0;i<3;i++)
        {
            if(num[i]>0)
            {
                while(num[i]>0)
                {
                    nums[j]=i;
                    j++;
                    num[i]--;
                }
            }
        }
    }
};
```