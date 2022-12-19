### 解题思路
1.先进行快速排序
2.然后再遍历查找出只出现一次的元素
时间复杂度：O(nlogn)因为用到了快速排序sort()
空间复杂度：O(1)
# 运行结果
执行用时 :40 ms, 在所有 C++ 提交中击败了9.22%的用户
内存消耗 :11.9 MB, 在所有 C++ 提交中击败了5.06%的用户
### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
          int len=nums.size();
          if(len==1)    return nums[0];
          sort(nums.begin(),nums.end());
          int i=0;
          for(i=0;i<len-1;i=i+2)
          {
              if(nums[i]!=nums[i+1])
                return nums[i];
              
          }
          if(i==len-1)  return nums[len-1];
          return 0;
    }
};
```