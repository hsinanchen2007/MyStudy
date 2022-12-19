### 解题思路
参考官方解法的双指针思路；
注意 return it1 - nums.begin() +1；  it1 - nums.begin()返回的是长度

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if(nums.size() <= 0)
        return nums.size();

       vector<int>::iterator it1;
       vector<int>::iterator it2;  
       it1 = nums.begin();
       for(it2 = nums.begin() + 1; it2 != nums.end(); it2++)
       {
           if(*it2 != *it1)
           {
               it1++;
              *it1 = *it2;
           }
       }    
       return it1 - nums.begin() +1;
      
    }

};
```