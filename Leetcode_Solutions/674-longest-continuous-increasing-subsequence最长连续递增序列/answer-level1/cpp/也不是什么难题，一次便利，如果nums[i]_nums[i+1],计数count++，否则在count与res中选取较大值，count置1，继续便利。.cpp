### 解题思路
![image.png](https://pic.leetcode-cn.com/1498dd23027f4a808943c64389f6cb55e8d3c97caf3843dff9fb6f3702262f13-image.png)

### 代码

```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return len;
        int count = 1,res = 0;
        for(int i = 0;i < len-1;i ++){
            if(nums[i] < nums[i+1] ){
                count ++;
            }
            else{
                res = max(res,count);
                count = 1;
            }
        }
//        std::cout<<res<<count<<endl;
        res = max(res,count);
        return res;
    }
};
```