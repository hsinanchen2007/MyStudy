### 解题思路
动态规划，分组，可以参考官方解答的第三种方法，此为C++的代码实现。

### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int* leftMax = new int[nums.size()];
        int* rightMax = new int[nums.size()];
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            if(i%k==0){
                leftMax[i] = nums[i];
            }else{
                leftMax[i] = max(leftMax[i-1],nums[i]);
            }
        }
        int rest = nums.size()%k;
        if(rest>=1){
            rightMax[nums.size()-1] = nums.back();
            for(int i=1;i<rest;i++){
                rightMax[nums.size()-1-i] = max(rightMax[nums.size()-i],nums[i]);
            }
        }
        for(int i=(int)(nums.size()-1-nums.size()%k);i>=0;i--){
            if(i%k==(k-1)){
                rightMax[i]=nums[i];
            }else{
                rightMax[i]=max(rightMax[i+1],nums[i]);
            }
        }
        for(int i=0;i<nums.size()-k+1;i++){
            int maxItem = max(rightMax[i],leftMax[i+k-1]);
            result.push_back(maxItem);
        }
        return result;
    }
};
```