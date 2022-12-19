### 解题思路
注意：这道题的两个易错点
1、要在交换两个数前判断(i<j)，否则会再换回去
2、i++；j--前要判断(i<j)，否则会出现溢出问题
swap()交换两个数

### 代码

```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(nums.size()==0) return nums;
        int i=0;
        int j=nums.size()-1;
        while(i<j)
        {
            while(nums[i]%2==1&&i<j) i++;
            while(nums[j]%2==0&&i<j) j--;
            if(i<j)
            {swap(nums[i],nums[j]);}
        }
        return nums;

    }
};
```