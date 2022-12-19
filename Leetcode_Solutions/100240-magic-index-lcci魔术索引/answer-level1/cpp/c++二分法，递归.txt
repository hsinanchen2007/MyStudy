```
class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        return findMagicIndex_helper(nums,0,nums.size()-1);
    }
    int findMagicIndex_helper(vector<int>& nums,int left,int right)
    {
        if(left==right)//base情形
        {
            if(nums[left]==left)return left;
            else return -1;
        }
        int mid=(left+right)/2;
        if(nums[mid]==mid)
        {
            //只需在前半部分寻找更小的下标
            int t=findMagicIndex_helper(nums,left,mid);
            return (t==-1)?mid:t;
        }
        else
        {
            //先在左边找，没找到再去右边找
            int t=findMagicIndex_helper(nums,left,mid);
            if(t!=-1)return t;
            else return findMagicIndex_helper(nums,mid+1,right);
        }
    }
};
```
