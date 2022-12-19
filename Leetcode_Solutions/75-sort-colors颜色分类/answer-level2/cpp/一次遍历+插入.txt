### 解题思路
设置**0计数器**

遍历到0时，插入到最前位置
遍历到1，插入到0计数器数字后一位
遍历到2，不用管

**注意：在插入之前要移除这个点，否则会引起 索引错位 **

### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        /**
            方法1:计数器_设置0计数器，1插入到0的后端，2不用管。0插入到0
            TC:O(N)
            SC:O(1)
        */
        int count = 0;// 0计数器

        for(int i=0;i<nums.size();++i)
        {
            if(nums[i] == 0)
            {
                ++count;
                nums.erase(nums.begin()+i);//先擦去，再插入
                nums.insert(nums.begin(),0);
            }
            else if(nums[i] == 1)
            {
                nums.erase(nums.begin()+i);//先擦去，再插入
                nums.insert(nums.begin()+count,1);
            }
        }
    }
};
```