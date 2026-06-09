### 解题思路
思路一：
基于快排的partition函数，此函数能把比选中数字小的排到左边，大的排到右边。
在此题中，如果选中的数字下标正好是n/2，那么正好就是他。如果选中下标大于n/2，则继续在左版部分寻找。典型的递归过程。
但是此法有可能超时。。。
思路二：
利用数组特性。
遍历是，保存数字和出现次数。下个数与保存的相同，则count+1，不同则-1。
如果次数为0了，就把当前访问的数字保存，count置1。
由于要找的数字次数比其他的数字出现次数总和还多，所以最后一次置1的数字就是对应得结果。

### 思路二C++代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //特殊
        if(nums.empty())
            return -1;
        //功能
        int count = 1;
        int res = nums[0];
        for(int i = 1;i<nums.size() ; i++)
        {
            if(count == 0)
            {
                res = nums[i];
                count = 1;
            }
            else if(nums[i] == res)
                count++;
            else
                count--;
        }
        return  res;
    }
};
```