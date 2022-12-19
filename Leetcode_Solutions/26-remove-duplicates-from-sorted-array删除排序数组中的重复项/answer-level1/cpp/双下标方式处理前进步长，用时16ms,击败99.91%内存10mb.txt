### 解题思路
此处撰写解题思路
双下标方式处理前进步长，
### 代码
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=1;
        if(nums.size()==0){
            return 0;
        }
        while(j<nums.size()){
            if(nums[i]==nums[j]){               
                j++;
            }else{
                nums[++i]=nums[j++];
            }
        }
        
        return i+1;
    }
};
```