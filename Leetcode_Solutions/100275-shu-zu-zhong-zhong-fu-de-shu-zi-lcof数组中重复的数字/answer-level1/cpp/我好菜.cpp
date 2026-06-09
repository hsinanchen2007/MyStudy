### 解题思路
学习一下array的用法

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        std::array<int,100000> hash {};
        int count = 0;
        for(int i=0;i<nums.size();++i)
            hash[nums[i]]++;
        while(count<100000){
            if(hash[count]>1){
                return count;
                break;
            }
            count++;
        }
        return -1;
    }
};
```