### 解题思路
发现用哈希效率好低
1.建立哈希表
2.查找出现频率为1的，由于要找频率为1，因此得遍历一遍。
怀疑自己思路是不是有问题，效率低

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
     unordered_map<int,int> mark;
     for(int i=0;i<nums.size();i++)
     {
        
         mark[nums[i]]++;
     }
      for(auto iter=mark.begin();iter!=mark.end();iter++)
      {
          if(iter->second==1)
          return iter->first;
      }
      return -1;
    }
};
```