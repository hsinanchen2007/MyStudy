### 解题思路
先使用快速排序，得到类似1，1，1，3，3，3，5，7，7，7的序列
每次将当前的元素与后两个元素分别进行比较，出现不同则为single number，每次向后移动3个位置，

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());//排序后得到类似2，2，2，3
        int len=nums.size();

        for(int i=0;i<=len-1;i=i+3)
        {
            if(i==len-1) //如果当前元素是最后一个元素,则为single number
            return nums[i];
            if(nums[i]!=nums[i+1]||nums[i]!=nums[i+2])//如果当前元素起的三个元素存在不同
            return nums[i];
        }
        return -1;
    }
};
```