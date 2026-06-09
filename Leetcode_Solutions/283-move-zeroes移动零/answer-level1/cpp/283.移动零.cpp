### 解题思路
1、原始搬移。
2、快慢游标，慢游标遇到0之后停住，等待下一个非零与他交换。

### 代码

```cpp
class Solution {
public:
    // 原始做法
    // void moveZeroes(vector<int>& nums) {
    //     int k = nums.size() - 1;
    //     int temp;
    //     for(int i=k;i>=0;--i){
    //         temp = nums[i];
    //         if(temp == 0){
    //             for(int j=i+1;j<k+1;++j){
    //                 nums[j-1] = nums[j]; 
    //             }
    //             nums[k] = temp;
    //             k--;
    //         }
    //     }
    // }
    // 由于是 0，可以有骚操作
    void moveZeroes(vector<int>& nums){
        int j=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i] != 0){
                nums[j++] = nums[i];
            }
        }
        while(j < nums.size()){
            nums[j++] = 0;
        }
    }
};
```