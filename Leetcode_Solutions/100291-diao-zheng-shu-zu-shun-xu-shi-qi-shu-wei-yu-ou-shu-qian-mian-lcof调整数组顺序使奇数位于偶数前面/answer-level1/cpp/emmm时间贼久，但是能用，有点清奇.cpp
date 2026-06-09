### 解题思路
就是使用了vector的方法，如果奇数就在前面插入，如果偶数就在vector后面插入，然后就完成了。时间挺久1548ms，希望有大佬能帮忙解答下怎么缩短执行时间

### 代码

```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int length = nums.size();
        vector<int> save;
        for(int i=0;i<length;i++){
            if(nums[i]%2 == 1)
                save.insert(save.begin(),nums[i]);
            else
                save.push_back(nums[i]);
        }
        return save;
    }
};
```