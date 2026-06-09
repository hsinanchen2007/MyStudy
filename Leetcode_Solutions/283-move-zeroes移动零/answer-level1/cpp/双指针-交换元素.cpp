### 解题思路
双指针思路大致如下：一个慢（j）指针，一个快（i）指针；当快指针指向的值不等于0时，将其与慢指针（此时的慢指针指向待交换的位置）进行交换，并使慢指针往后挪一位，指向新的代交换位置。

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,j;
        for(i=0,j=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
}; 
```