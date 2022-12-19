# 疑惑：为什么使用哈希表之后，时间效率还是没有提升上去？
# 哈希表
执行用时 :40 ms, 在所有 C++ 提交中击败了9.22%的用户
内存消耗 :13.4 MB, 在所有 C++ 提交中击败了5.06%
### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
          unordered_set<int> hashset;
          for(int i=0;i<nums.size();i++)
          {
              //如果该元素哈希表中没有，则插入
            if(hashset.find(nums[i])==hashset.end())
            {   
                hashset.insert(nums[i]);
            }
            else
            {
                //如果已经有则擦除
                hashset.erase(nums[i]);
            }
          }
          auto ans=hashset.begin();
          return *ans;
    }
};
```
# 快速排序
## 解题思路
1.先进行快速排序
2.然后再遍历查找出只出现一次的元素
时间复杂度：O(nlogn)因为用到了快速排序sort()
空间复杂度：O(1)

# 运行结果
执行用时 :40 ms, 在所有 C++ 提交中击败了9.22%的用户
内存消耗 :11.9 MB, 在所有 C++ 提交中击败了5.06%的用户

# 代码
```
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
