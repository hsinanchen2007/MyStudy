### 解题思路
执行用时 :16 ms, 在所有 C++ 提交中击败了60.72%的用户

### 代码

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> map;
        for(auto num: nums){
            map.insert(num);
        }
        int ans = 0;
        for(auto num : map){
            if(num != INT_MIN && map.count(num-1)){
                continue;
            }
            int cnt = 1;
            while(map.count(num+1)){
                num++;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```