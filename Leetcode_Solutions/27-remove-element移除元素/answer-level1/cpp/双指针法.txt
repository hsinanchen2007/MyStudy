### 解题思路
1.判断是否为空，为空直接返回（leetcode永远考虑这种情况）；
2.指针i往前移动，碰到nums[i]==val的情况，则跳过，并i++;否则让nums[j]=nums[i],并同时往前移动一个位置。
3.注意边界情况，i如果到了最后一个位置，应该注意不能再让i++，否则边界溢出，所以增加一个判断条件，如果到达了边界，那么有两种情况：nums[i]==val,此时直接跳出循环，返回即可；否则让nums[j]=nums[i],j++。

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0)return 0;
        int i=0,j=0;
        while(i<nums.size()){
          while(nums[i]==val){
              if(i==nums.size()-1)break;
              i++;
          }
          if(i==nums.size()-1&&nums[i]==val)break;
          nums[j]=nums[i];
          i++;j++;
          
        }
        return j;
        
    }
};
```