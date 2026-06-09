### 解题思路
此处撰写解题思路
交换一次性遍历

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int zeroCount = 0;
        for(int i =0 ; i< size; i++){
            
            if (nums[i] == 0) {
                zeroCount ++ ;
            }
            
            if(nums[i] != 0){
                nums[i-zeroCount] = nums[i];
                if(zeroCount!=0){
                    nums[i]=0;
                }
            }
        }
    }
};
```