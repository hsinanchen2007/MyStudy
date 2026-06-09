```c++ []
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; ++i){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            
            int l = i + 1;
            int r = n - 1;
            
            while(l < r){
                while(l > i+1 && l < r && nums[l] == nums[l-1]){
                    l++;
                }
                while(r < n-2 &&  l < r && nums[r] == nums[r+1]){
                    r--;
                }
                if(l < r){
                    int sum = nums[i] + nums[l] + nums[r];
                    if(sum == 0){
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[l]);
                        t.push_back(nums[r]);
                        ans.push_back(t);
                        l++;
                        r--;
                    }else if(sum < 0){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
        }
        
        return ans;
    }
};
```
```python []
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        nums.sort()
        
        for i in range(0,n):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            
            l = i + 1
            r = n - 1
            while l < r:
                while l > (i+1) and l < r and nums[l] == nums[l-1]:
                    l += 1
                while r < (n-1) and l < r and nums[r] == nums[r+1]:
                    r -= 1
                
                if l < r:
                    s = nums[i] + nums[l] + nums[r]
                    if s == 0:
                        t = []
                        t.append(nums[i])
                        t.append(nums[l])
                        t.append(nums[r])
                        ans.append(t)
                        l += 1
                        r -= 1
                    elif s > 0:
                        r -= 1
                    else:
                        l += 1
            
        return ans
```

