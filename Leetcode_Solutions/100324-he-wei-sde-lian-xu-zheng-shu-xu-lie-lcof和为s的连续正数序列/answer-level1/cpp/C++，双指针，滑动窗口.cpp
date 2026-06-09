### 解题思路
双指针法+滑动窗口确定z数组范围

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        int l = 1, r = 2;  //双指针法，计算[l, r]之间的数组大小

        while(l <= (target/2)){
            if((((l+r)*(r-l+1))/2) == target){
                vector<int> tmpvec;
                for(int i = l; i <= r; ++i) tmpvec.push_back(i);
                ans.push_back(tmpvec);
                ++l;
            }
            if((((l+r)*(r-l+1))/2) < target){
                ++r;
            }
            else if((((l+r)*(r-l+1))/2) > target){
                ++l;
            }
        }

        return ans;
    }
};
```