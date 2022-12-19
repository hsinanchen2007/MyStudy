### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int a[100001]={0};
        for(int i=0;i<nums.size();i++)
        {
            a[50000-nums[i]]++;
        }
        int j;
        int k=0;
        for(j=100000;j>0;j--)
        {
            if(a[j]>=1&&k+1<=nums.size()){
                while(a[j]>0)
                {nums[k++]=50000-j;a[j]--;}
            }
            else if(a[j]==1&&k==nums.size())
            {
                nums[k]=50000-j;
                break;
            }
        }
        return nums;
    }
};
```