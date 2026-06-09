### 解题思路
从数组第一个值开始，分别计算每个值从当前位置开始到末尾的若干序列的和（序列长度为1——（数组长度-当前值在数组中的位置）），找到其中的最大值，用一个数组max保存。遍历这个数组，找最大值即可

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int right = nums.size();
        int max[right];
        
        for(int j = 0; j < nums.size(); j++){
            int temp = nums[j];
            max[j] = temp;
            for(int i = j+1; i < nums.size(); i++){
                temp += nums[i];
                if(max[j] <= temp)
                    max[j] = temp;
            }
        }

        int MAX = max[0];
        for(int k = 1; k < nums.size(); k++){
            if(max[k] >= MAX)
                MAX = max[k];
        }
        return MAX;
    }
};
```