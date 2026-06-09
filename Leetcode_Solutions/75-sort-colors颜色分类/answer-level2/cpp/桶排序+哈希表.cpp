```
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        //不知道该叫桶排序还是叫哈希吧方法
        //因为知道总共是三个元素会出现，统计三个元素的出现的次数即可
        vector<int> temp(3,0);
        for(int i=0;i<nums.size();i++)
        {
            temp[nums[i]]++;
        }
        int j=0;
        for(int i=0;i<3;i++)
        {
            while(temp[i]>0) 
            {
                nums[j++]=i;
                temp[i]--;
            }
        }
    }
};
```
