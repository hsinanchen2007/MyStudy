从左找到第一个不为0的数，从右找到第一个不为2的数
此时左边1||2，右边0||1
若左1右0，交换，左++
若左1右1，此种情况最复杂，用tl保存这个左的下标l，从l+1往右搜索到第一个为0的数，交换nums[l]和nums[tl]
然后l++
若左2右0，交换，l++，r--
若左2右1，交换，r--
```
class Solution {
public:
    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
    void sortColors(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            while(l<r&&nums[l]==0)
            l++;
            while(l<r&&nums[r]==2)
            r--;
            if(l>=r)
            break;
            if(nums[l]==1&&nums[r]==0)
            {
                swap(nums[l],nums[r]);
                l++;
                continue;
            }
            if(nums[l]==1&&nums[r]==1)
            {
                int lf=l;
                while(l<r){
                    if(nums[l]==0)
                    break;
                    l++;
                }
                if(l<r)
                {
                    swap(nums[l],nums[lf]);
                }
                l=lf+1;
                continue;
            }
            if(nums[l]==2&&nums[r]==0)
            {
                swap(nums[l],nums[r]);
                l++;
                r--;
                continue;
            }
            if(nums[l]==2&&nums[r]==1)
            {
                swap(nums[l],nums[r]);
                r--;
                continue;
            }
        }
    }
};
```
