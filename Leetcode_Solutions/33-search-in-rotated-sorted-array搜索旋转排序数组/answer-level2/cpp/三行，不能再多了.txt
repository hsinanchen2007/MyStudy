有现成的轮子，干嘛不用呢
```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto pos=find(nums.begin(),nums.end(),target);
        if(pos!=nums.end())return pos-nums.begin();
        return -1;
    }
};
```