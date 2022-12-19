### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n=nums.size();
        int arry[50000];int j=0;int p=n-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==1)
            {
                arry[j]=nums[i];
                j++;
            }
            else
            {
                arry[p]=nums[i];
                p--;

            }
          
        }
          for(int i=0;i<nums.size();i++)
            {
                nums[i]=arry[i];
            }
        return nums;



    }
};
```