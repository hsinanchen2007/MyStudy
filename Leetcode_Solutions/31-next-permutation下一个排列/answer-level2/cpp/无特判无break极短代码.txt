### 解题思路
无特判无break极短代码
### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len=nums.size();
        int st=-1;
        for(int i=len-2;i>=0&&st==-1;i--)
            if(nums[i]<nums[i+1])
                for(int j=len-1;j>=i+1&&st==-1;j--)
                    if(nums[j]>nums[i]){
                        st=i;
                        len=nums[i]; 
                        nums[i]=nums[j];
                        nums[j]=len;
                    }
        sort(nums.begin()+st+1,nums.end());
    }
};
```