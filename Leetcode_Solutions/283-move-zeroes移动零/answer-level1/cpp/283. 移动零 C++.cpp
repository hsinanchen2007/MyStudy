### 解题思路
1.先给数组中的零元素计数。
2.将原数组中所有非零元素压入ans元素。
3.在ans中压入零元素。
4.将ans中的元素中赋值到nums中。

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
            int n = nums.size();

    // Count the zeroes
    int numZeroes = 0;
    for(int i = 0;i < n;i++){
        numZeroes += (nums[i] == 0);
    }

    // Make all the non-zero elements retain their original order.
    vector<int> ans;
    for(int i = 0;i < n;i++){
        if(nums[i] != 0){
            ans.push_back(nums[i]);
        }
    }

    // Move all zeroes to the end
    while(numZeroes--){
        ans.push_back(0);
    }

    // Combine the result
    for(int i = 0;i < n;i++){
        nums[i] = ans[i];
    }
    }
};
```