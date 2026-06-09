### 解题思路
注意理解贪心处理思维，处理连续总和问题。

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int currNum=nums[0],maxNum=nums[0],size=nums.size();

        for(int i=1;i<size;i++){
            int temp=nums[i];
            currNum= max(temp,temp+currNum);
            maxNum=max(currNum,maxNum);
        }

        return maxNum;

    }
};
```