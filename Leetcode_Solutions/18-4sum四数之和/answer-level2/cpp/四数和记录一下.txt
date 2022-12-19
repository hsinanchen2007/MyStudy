### 解题思路
先排序，再外面两重遍历，里面双指针法找。一开始要100ms，后来加了判断vector大小以及前四个数的和与target的比较，变成了48ms，效率不太理想。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        if(nums.size()<4)
            return res;
        if(nums[0]+nums[1]+nums[2]+nums[3]>target)
            return res;
        int n = nums.size();
        for(int i = 0;i<n-3;i++){
            if(i>0&&nums[i]==nums[i-1])
                continue;
            for(int j = i+1;j<n-2;j++){
                if(j>i+1&&nums[j]==nums[j-1])
                    continue;
                int l=j+1,r=n-1;
                
                while(l<r){
                    int sum=nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum==target){
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        res.push_back(temp);
                        l++;
                        while(l<n&&nums[l]==nums[l-1])
                            l++;
                        r--;
                        while(r>-1&&nums[r]==nums[r+1])
                            r--;
                    }
                    else if(sum<target){
                        l++;
                        while(l<n&&nums[l]==nums[l-1])
                            l++;
                    }else{
                        r--;
                        while(r>-1&&nums[r]==nums[r+1])
                            r--;
                    }
                }

            }
        }
        return res;
    }
};
```