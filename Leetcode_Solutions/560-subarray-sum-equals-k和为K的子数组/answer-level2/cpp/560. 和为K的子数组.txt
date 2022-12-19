### 解题思路
没啥技术含量的暴力解法，两层循环，遍历出所有情况

### 代码

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len=nums.size();
        int count=0;
        vector<int> res(len,0);
        for (int i=0;i<len;i++){
            for(int j=0;j<=i;j++){
                res[j]+=nums[i];
                if(res[j]==k) count++;
            }
        }
        return count;
    }
};
```
题解区有dalao利用hash表的优秀解法 NB


