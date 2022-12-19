### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        std::vector<int> idex;
        for(int i = 0 ; i < nums.size() ; i++){
            idex.push_back(i + nums[i]);
        }
        int jump = 0 ;
        int max_index = idex[0];
        while(jump < nums.size() && jump <= max_index ){
            if(max_index < idex[jump]){
                max_index = idex[jump];
            }
            jump++; 
            if(jump == nums.size()){
                return true;
            }
        }
        return false;
    }
};
```