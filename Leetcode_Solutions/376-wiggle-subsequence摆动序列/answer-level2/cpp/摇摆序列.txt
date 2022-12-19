### 解题思路
有限自动机实现 状态转化
只有在转台转化的时候 长度才会增加
begain->up len++ (s[i-1]<s[i])
begain->down len++ (s[i-1]>s[i]) 否则 状态不变
up->down len++ (s[i-1]>s[i]) 否则 状态不变 
down->up len++(s[i-1]<s[i])  否则 状态不变
### 代码

```cpp
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        const int begain=0;
        const int down=1;
        const int up=2;
        int state=begain;
        int len=1;
        if(nums.size()<2) return nums.size();//小于2就直接返回
        for(int i=1;i<nums.size();i++)//从第二个元素开始
        {
            switch(state)
            {
                case begain:
                if(nums[i-1]<nums[i])
                {
                    len++;
                    state=up;
                }
                else if(nums[i-1]>nums[i])
                {
                    len++;
                    state=down;
                }
                else state=begain;
                break;

                case up:
                if(nums[i-1]>nums[i])
                {
                    len++;
                    state=down;
                }
                else 
                {
                    state=up;
                }
                break;

                case down:
                if(nums[i-1]<nums[i])
                {
                    len++;
                    state=up;
                }
                else state=down;
                break;
            }
        }
        return len;
    }
};
```