### 解题思路

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2)
           return nums.size();
        int num=nums[0];
        for(vector<int>::iterator it=nums.begin()+1;it<nums.end();it++)
        {
            if(num==*it)  //若相等，则删除前一项，指针前移一位
            {
                nums.erase(it);
                it--;
            }
            else       //若不相等，改变比较值
                num=*it;
        }
        return nums.size();
    }
};
```