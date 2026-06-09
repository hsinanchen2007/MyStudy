### 解题思路
首先对所有因子相乘，得到最终的结果。
如果该结果不为0，则再一次循环中，对每个数相除，就可以得到最终的结果；
如果结果为0，则就进行两次循环就可以搞定了。

### 代码

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int temp = 1;
        for(int i=0;i<nums.size();i++){
            temp = temp * nums[i];
        }
        
        for(int i = 0; i < nums.size();i++){
            if(temp != 0) res.push_back(temp / nums[i]);
            else{
                int ans = 1;
                for(int j=0;j<nums.size();j++){
                    if(i != j) ans = ans * nums[j];
                }
                res.push_back(ans);
            }
        }
        return res;
    }
};
```