### 解题思路
此处撰写解题思路
首先对空向量特殊处理，若是空向量，直接返回向量大小为0；否则设置向量大小zsize为1，并设两个游标cur0、cur1，开始时分别置于0、1位置，利用游标2（cur1）遍历向量，若游标1、2所指向量值不同，则交换游标cur0+1和cur1中的数据，并将cur0向后移动i一位，同时将更新向量大小（size++）。最后返回size即可。
### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int cur0=0;
        int size=1;
        for (int cur1=1;cur1<nums.size();cur1++)
        {
            if(nums[cur1]!=nums[cur0])
            {   
                swap(nums[cur0+1],nums[cur1]);
                cur0++;
                size++;
            }
        }
        return size;
    }
};
```