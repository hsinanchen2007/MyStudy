### 解题思路
&优先级比==低，一定要加括号啊！！

### 代码

```cpp
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int whole = 0,part1 = 0,part2 = 0,div = 1;
        vector<int> res;
        for(auto i = 0;i < nums.size();i++){
            whole ^= nums[i];
        }
        while(0 == (div&whole))
            div <<= 1;
        for(auto i = 0;i < nums.size();i++){
            if(0 == (nums[i]&div))
                part1 ^= nums[i];
            else
                part2 ^= nums[i];
        }
        res.push_back(part1);
        res.push_back(part2);
        return res;
    }
};
```