### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
    int result,count=0;
    if (nums.size()==1) {
        return nums[0];
    }
    else if(nums.size()==2)
        return max(nums[0],nums[1]);
    else{
        set<int> S(nums.begin(),nums.end());
        if (S.size()==1) return *S.begin();
        if (S.size()==2) {
            return max(*S.begin(),*(++S.begin()));
        }
        set<int>::iterator it;
        for (it=--S.end(); it!=--S.begin(); it--) {
            count++;
            if (count==3) {
                result=*it;
            }
        }
        
    }
    return result;
}
};
```