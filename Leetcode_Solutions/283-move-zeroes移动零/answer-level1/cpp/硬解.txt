### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         int s=nums.size();
         for(int i=0;i<s;){
             if(nums[i]==0){
                 nums.push_back(0);
                 nums.erase(nums.begin()+i);
                 s--;
             }
             else i++;
         }    
         
    }
};
```执行用时 :
16 ms
, 在所有 C++ 提交中击败了
30.10%
的用户
内存消耗 :
9.1 MB
, 在所有 C++ 提交中击败了
100.00%
的用户