### 解题思路
此处撰写解题思路
只有你死活跳不过那个零的时候你才走不下去。
### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool s=true;
        //你能跳跃的最大长度是当前位置数，但是你也可以选择不跳这个长度吖
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0 && i<nums.size()-1) //有跳不过去的危险,0要是最后一个元素，
                                              //那就很随意的跳过
            {
                int j=i-1;
                bool temp=false;//假定是跳不过去的
                for(j;j>=0;j--)
                {
                    if(nums[j]>i-j)
                    {
                        temp=true;
                        break;
                    }
                }
                if(temp==false)
                {
                    s=false;
                    break;
                }
            }
        }
        return s;
    }
};
```