### 解题思路
第一次双100%留念
![lt.png](https://pic.leetcode-cn.com/282df8712804b418be42f16a80a4be6cd6977c50acee17d0863d9c2cb28066f0-lt.png)

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> vv;
        map<int,int> m;
        vv.push_back(v);
        if(nums.size()==0)return vv;
        for(int i=0;i<nums.size();i++){
            v.clear();
            v.push_back(nums[i]);
            vv.push_back(v);
            m[nums[i]] = i;
        }
        if(nums.size()==1)return vv;
        int begin=1,end=nums.size();
        for(int i=2;i<nums.size();i++){
            for(int j=begin;j<=end;j++){
                for(int k=m[vv[j][vv[j].size()-1]]+1;k<nums.size();k++){
                    v.clear();
                    v.assign(vv[j].begin(),vv[j].end());
                    v.push_back(nums[k]);
                    vv.push_back(v);
                }
            }
            begin = end+1;
            end = vv.size()-1;
        }
        vv.push_back(nums);
        return vv;
    }
};
```