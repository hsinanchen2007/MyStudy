
![fsdfdsfdsfdsfdsfdsfsdf.PNG](https://pic.leetcode-cn.com/a39bd39fdd9633a0d6536a7b5b4d805ec989bac83d0a3b9e1d51e908373a9f88-fsdfdsfdsfdsfdsfdsfsdf.PNG)

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto iter1=nums.begin();
        for(auto iter2=iter1;iter2!=nums.end();++iter2){
            if(*iter2!=val){
                *iter1=*iter2;
                ++iter1;
            }
        }
        return iter1-nums.begin();
    }
};
```