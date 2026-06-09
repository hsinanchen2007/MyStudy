### 解题思路
1.首先从后往前找最大逆序
2.如果整串为逆序，直接sort搞定
3.如果，不是整串为逆序，则从逆序部分找出大于（逆序串首的前一个元素）的最小值，交换，再把逆序串范围sort
### 代码

```cpp
class Solution {
public:
    void swap(vector<int>& nums,int a,int b)
    {
        int mid=nums[a];
        nums[a]=nums[b];
        nums[b]=mid;
    }
    void nextPermutation(vector<int>& nums) {
        int l=nums.size();
        int i=l-1;
        int flag=0;
        for(;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            int pos=i;
            for(int j=i;j<l;j++)
            {
                if(nums[j]>nums[i-1]&&nums[j]<nums[pos])
                    pos=j;
            }
            swap(nums,i-1,pos);
            sort(nums.begin()+i,nums.end());
        }
        else
            sort(nums.begin(),nums.end());
        return ;
    }
};
```