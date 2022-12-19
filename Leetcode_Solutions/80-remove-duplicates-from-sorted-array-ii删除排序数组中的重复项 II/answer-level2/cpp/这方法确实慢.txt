### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len(1);
        for(int i=1;i<nums.size();++i){
            while(i<nums.size()&&nums[i]==nums[i-1]){
                len++;
                if(len>2){
                    nums.erase(nums.begin()+i);
                    len--;
                }
                else i++;
            }
            len=1;
        }
        return nums.size();
    }
};
```