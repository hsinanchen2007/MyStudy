### 解题思路
1. 首先要假设第一个数过半并设count=0,res=0;
2. 从第一个数开始遍历，后面的数如果和假设相同则count++,不太则count--;
3. 当count为0时，更换新的数字为侯选数

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int res=0;
        for(auto i : nums)
        {
            if(count==0)
            {
                res=i;
                count++;
            }
            else
            {
                res==i ? count++ : count--;
            }
        }
        return res;
    }
};
```