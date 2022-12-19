### 解题思路
此处撰写解题思路
先复制一份数组，因为数组排序后会打乱原本的数组位置
很简单的想法就是先对数组排序，利用sort()算法
然后排除一些异常因素
然后再遍历一次数组，与copy数组去比对，找到这个值原本在的位置。
### 代码

```cpp
class Solution {
public:
    int dominantIndex(vector<int>& nums)
     {
      vector<int> arr (nums.begin(),nums.end());
      sort(nums.begin(),nums.end(),greater<int>());
      if (nums.size()==0)
      return -1;
      if (nums.size()==1)
      return 0;
      if(nums[0] >= nums[1]*2)
      {
         for(int i=0; i<nums.size();i++)
        {
          if (nums[0] == arr[i])
             return i;
        }
      }
      return -1;
     }
};
```