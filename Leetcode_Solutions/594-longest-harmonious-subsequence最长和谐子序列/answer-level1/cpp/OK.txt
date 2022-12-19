### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int max1=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            int key=it->first;
            if(mp.find(key+1)!=mp.end()){
                int d=mp[key+1]+mp[key];
                max1=max(max1,d);
            }
        }
        return max1;
    }
};
```