### 解题思路
![屏幕快照 2020-04-08 11.03.22.png](https://pic.leetcode-cn.com/9af29186751f21df0ddd7e300da326f9301ce8dac34ab112e8e6f15b13dc108a-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-04-08%2011.03.22.png)
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        bool res=false;
        sort(nums.begin(), nums.end(), less<int>());

//        for (int i=0; i<nums.size(); i++) {
//            cout<<nums[i]<<"\t";
//        }
//        cout<<endl;
        
        int zero_cnt=0;
        
        int i=0;
        while (nums[i]==0) {
            zero_cnt++;
            i++;
        }
        
        int tmp=nums[i];
        int interval=0;
        i++;
        for (; i<nums.size(); i++) {
            if (nums[i]==tmp+1) {
                tmp++;
            }
            else if(nums[i]>tmp+1)
            {
                interval=interval+nums[i]-tmp-1;
                tmp=nums[i];
            }
            else
            {
                return false;
            }
        }
        
        
//        cout<<zero_cnt<<endl;
//        cout<<interval<<endl;
        
        if (zero_cnt>=interval) {
            return true;
        }
        else
        {
            return false;
        }
    }
};
```