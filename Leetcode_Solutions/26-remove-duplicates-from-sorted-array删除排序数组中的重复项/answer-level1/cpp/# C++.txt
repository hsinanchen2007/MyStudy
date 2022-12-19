
记录当前元素，找到相同元素就删除

```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cmp;
        int numLen = nums.size();
        
        if (numLen == 0 || numLen == 1)
            return numLen;
        
        int i = 0;
        while(i<nums.size())
        {
            if(i == nums.size()-1)
            {
                i++;
                continue;
            }
            cmp = nums.at(i);
            if(cmp == nums.at(i+1))
            {
                nums.erase(nums.begin()+i+1);
            }
            else
                i++;
        }
        return i;
    }
};
```
