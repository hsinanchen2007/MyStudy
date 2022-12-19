

### 代码

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int,int>m;
        for(size_t i=0;i<nums.size();++i){//把每个元素的次数都算一遍
            ++m[nums[i]];
        }
        vector<int>vec;
        for(size_t i=0;i<nums.size();++i){
            auto it1=m.find(nums[i]);//找到这个这个元素，返回一个指向他的迭代器
            auto it2=m.begin();
            int num=0;
            while(it2!=it1){
                num+=it2->second;
                ++it2;
            }
            vec.emplace_back(num);
        }
        return vec;
    }
};
```