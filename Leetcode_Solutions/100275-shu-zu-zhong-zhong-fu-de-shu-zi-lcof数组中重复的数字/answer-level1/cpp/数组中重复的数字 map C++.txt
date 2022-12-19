### 解题思路
此处撰写解题思路
建立键值对 键为nums[i]  值为nums[i]出现的次数 
遍历nums数组  出现nums[i] 对应的值就+1 
同时判断nums[i]出现次数是否大于1 是的话 直接return
### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        map<int,int> temp;
        for(int i=0;i<nums.size();i++){
            temp[nums[i]]++;
            if(temp[nums[i]]>1)
                return nums[i];
        }
        return -1;

    }
};
```