### 解题思路
(1) 使用哈希表两两分块

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<4) return res;
        sort(nums.begin(), nums.end());
        int n =nums.size();
        if(nums[0]+nums[1]+nums[2]+nums[3] > target) return res;
        if(nums[n-4]+nums[n-3]+nums[n-2]+nums[n-1] < target) return res; 
        unordered_map<int, vector<vector<int>> > map;

        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                int key = nums[i] + nums[j];
                if (map.count(target - key)>0) {
                    for(auto c : map[target - key]) {
                        if(i!=c[0] && i!=c[1]) {
                            if(j!=c[0] && j!= c[1]) {
                                //res.push_back({c[0],c[1],i,j});
                                vector<int> temp {nums[c[0]], nums[c[1]], nums[i], nums[j]};
                                sort(temp.begin(), temp.end());
                                res.push_back(temp);
                            }
                        }
                    }
                } 
                map[key].push_back({i, j});
            }
        }
        set<vector<int>> s(res.begin(), res.end());
        res.assign(s.begin(), s.end());
        return res;
    }
};
```
(2) 双指针法
```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<4) return res;
        sort(nums.begin(), nums.end());
        int a, b, c, d;                                     //下标
        int n = nums.size();
        for(a=0; a<=n-4; a++) {
            if(a>0 && nums[a]==nums[a-1]) continue;         //避免出现重复
            for(b=a+1; b<=n-3; b++) {
                if(b>a+1 && nums[b]==nums[b-1]) continue;
                d = n-1;
                for(c=b+1; c<d; ) {
                    if(c>b+1 && nums[c]==nums[c-1]) {
                        c++;
                      continue;  
                    }
                    if(d<n-1 && nums[d]==nums[d+1]) {
                        d--;
                      continue;  
                    } 
                    if(nums[a]+nums[b]+nums[c]+nums[d] < target) {
                        c++;
                    } else if(nums[a]+nums[b]+nums[c]+nums[d] > target) {
                        d--;
                    } else {
                        res.push_back({nums[a], nums[b], nums[c], nums[d]});                  

                        c++;
                        d--;
                    }
                }
            }
        }
        return res;
    }
};
```