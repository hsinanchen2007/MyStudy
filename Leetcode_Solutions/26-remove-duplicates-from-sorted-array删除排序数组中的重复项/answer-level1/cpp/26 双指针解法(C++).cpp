 解题思路：双指针，一个指针始终指向的是可能重复与元素的第一个数，另一个指针遍历数组


```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       
        //首先考虑特殊情况
        if(nums.size()==0)
        {
            return 0;//不考虑这种情况过不了
        }

        int j=0;//这个就是指向可能是重复元素的第一个数
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[j])
            {
                j++;
                nums[j]=nums[i];
            }
        }
        return j+1;//因为最后要的数组长度,j表示下标，所以最后+1;
    }
};
```
