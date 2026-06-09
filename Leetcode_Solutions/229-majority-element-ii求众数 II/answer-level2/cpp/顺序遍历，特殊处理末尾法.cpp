### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         if(nums.size()<2||(nums.size()==2&&nums[0]!=nums[1]))                  return nums;
         sort(nums.begin(),nums.end());
         vector<int> major;
         int limit=nums.size()/3+1,count=1;

         for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])
                 count++;
            else{
               if(count>=limit)
                 major.push_back(nums[i-1]); 
                count=1;
               }
         }
    if(count>=limit)  major.push_back(nums[nums.size()-1]);
    return major;         
    }
};
/*
首先排除hashmap的方法，这种方法空间复杂度为O(n);
1.排序法，再顺序遍历
2.顺序遍历计数法
3.注意处理排序后的尾巴，比如1，2，2，2此时会出现尾部计数器count未被处理的情况，需要单独处理。
*/

```