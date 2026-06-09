### 解题思路
max代表最大值，max1代表第二大的值
![NGDV~\[3~T3~}T$0~A0O4}}W.png](https://pic.leetcode-cn.com/30807411446b0f5e8e502f746796b07727f196eb404d5698c684bb7d32082863-NGDV~%5B3~T3~%7DT$0~A0O4%7D%7DW.png)


### 代码

```cpp
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max=nums[0],max1=INT_MIN,index=0,size=nums.size();
        if(size==1)
            return 0;
        for(int i=0;i<size;i++)
        {
            if(max<nums[i])
            {
                max1=max;
                max=nums[i];
                index=i;
            }
            if(nums[i]>max1&&nums[i]<max)
                max1=nums[i];
        }
        return max>=max1*2?index:-1;
    }
};
```