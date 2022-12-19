### 解题思路
此处撰写解题思路
a+b+c = 0 -》 -a = b+c
先对原数组进行排序
双指针法。当a不动时，b+c 小于-a，就对b++，如果大于c--；

一定记得要去重！！


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
       
        int size = nums.size();
         if(size <= 2) return res;
        //对nums进行排序
        sort(nums.begin(),nums.end());

        //双指针
        int pointSize = size - 2;
        //以最左边的数为结果，当nums[i] > 0，就break.
        for(int i = 0;  i < pointSize; ++i)
        {
            int now = nums[i];
            if(nums[i] > 0)
            {
                break;
            }
            int indexNow = 0 - now;
            int lo = i + 1;
            int hi = size - 1;
            //当nums[lo] + num[hi] == indexnow。则符合情况。
            while(lo < hi)
            {
                int intLo = nums[lo];
                int intHi = nums[hi];
                if(intLo + intHi == indexNow)
                {
                    vector<int> mvec{now,intLo,intHi};
                    res.push_back(mvec);
                    //去重
                    while(lo < hi && nums[lo] == intLo)
                    {
                        lo++;
                    }
                    while( lo < hi && nums[hi] == intHi)
                    {
                        hi--;
                    }
                }
                else if(intLo + intHi < indexNow)
                {
                    lo++;
                }
                else if(intLo + intHi > indexNow)
                {
                    hi--;
                }
            }
            while(i + 1 < pointSize && nums[i+1] == nums[i])
            {
                i++;
            }
        }
        return res;
      
    }
};
```