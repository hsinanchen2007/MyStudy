### 解题思路
使用pre2，pre1记录记录前2天，前1天的最大预约时间，无需dp数组
![image.png](https://pic.leetcode-cn.com/72db7d15c800d1052adce89c7212b93cab98a1a820a5175294b141ddc39dcc5f-image.png)


### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.empty()) return 0;
        //pre2，pre1记录前2天，前1天的最大预约时间
        int pre2=0,pre1=0,now=nums[0];        
        for(int i=1;i<nums.size();i++)//i=1时pre1才有值
        {
            pre2=pre1;
            pre1=now;
            now=max(pre1,pre2+nums[i]);
        }
        return now;
    }
};
```