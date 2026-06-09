### 解题思路
用两个指针l,r分别移动进行判断。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>>ans;
        vector<int>res;
        int l = 1, r = 2;
        while(l < r){
            int sum = (r - l + 1) * (l + r) / 2;
            //int sum = (r - l) * (l + r) / 2;不行？？？
            if(sum < target){
                r += 1;
            }
            else if(sum > target){
                l += 1;
            }
            else if(sum == target){
                res.clear();
                for(int i = l;i <= r;i ++){
                    res.emplace_back(i);
                    }
                ans.emplace_back(res);
                l++;
                
            }

        }
        return ans;
    }
};
```