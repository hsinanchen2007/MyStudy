遍历数组
并将数组元素作为数组索引的值大于nums.size()时说明该值重复，否则加对应值加nums.size()

``` C++
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res;
        int len=nums.size();
        for(int i=0;i<len;i++)
        {
            int index=nums[i]%len;
            if(nums[index]>len)
            {
                res=index;
                break;
            }
            nums[index]+=len;
        }
        return res;
    }
};
```