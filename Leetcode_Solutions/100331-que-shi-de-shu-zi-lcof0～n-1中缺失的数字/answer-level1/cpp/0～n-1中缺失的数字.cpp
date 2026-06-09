### 解题思路
![image.png](https://pic.leetcode-cn.com/530ea7eb1a339757753e350c6008cde107b3ec84ed476d0629681762aad8cc94-image.png)


### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
            if(i!=nums[i]) return i;
        return nums.size();
    }
};
```