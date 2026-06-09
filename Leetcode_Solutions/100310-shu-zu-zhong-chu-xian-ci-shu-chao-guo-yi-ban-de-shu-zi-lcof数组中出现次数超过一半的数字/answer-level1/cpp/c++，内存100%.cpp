### 解题思路
此处撰写解题思路
执行用时 :
80 ms
, 在所有 C++ 提交中击败了
5.92%
的用户
内存消耗 :
19.1 MB
, 在所有 C++ 提交中击败了
100.00%
的用户
时间换空间··，先排序然后一个个遍历过去。可能不聪明但是也是一种方法

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int number=0;
       int output=0;
       if(nums.size()==1)
       return nums[0];
       
       for(int i=0;i<nums.size()-1;i++)
       {
           if(nums[i]==nums[i+1])
           {
               number++;
               if(number>=nums.size()/2)
               {
                   output=nums[i];
                   break;
               }
               
           }
           else
           number=0;


       }
       return output;

    }
};
```